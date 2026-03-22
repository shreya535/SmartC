import os
import subprocess
from flask import Flask, render_template, request, jsonify
from groq import Groq

app = Flask(__name__)

# ── Config ──
COMPILER_DIR = os.path.join(os.path.dirname(__file__), '..', 'compiler')
GROQ_API_KEY = "API_KEY"  # paste your gsk_... key here

client = Groq(api_key=GROQ_API_KEY)

# ── Helper: run compiler pipeline ──
def run_compiler(code):
    # Write user code to input.c
    input_path   = os.path.join(COMPILER_DIR, 'input.c')
    output_path  = os.path.join(COMPILER_DIR, 'output.c')
    report_path  = os.path.join(COMPILER_DIR, 'report.txt')
    fixed_path   = os.path.join(COMPILER_DIR, 'fixed_output.c')

    with open(input_path, 'w') as f:
        f.write(code)

    # Step 1: Preprocessor
    subprocess.run(
        [os.path.join(COMPILER_DIR, 'preprocessor'), input_path, output_path],
        capture_output=True
    )

    # Step 2: Parser + Semantic + Fix Engine
    subprocess.run(
        [os.path.join(COMPILER_DIR, 'smartc'), output_path, report_path, fixed_path],
        capture_output=True
    )

    # Read results
    errors = ""
    fixed  = ""
    report = ""

    try:
        with open(report_path, 'r') as f:
            report = f.read()
    except:
        report = "No report generated."

    try:
        with open(fixed_path, 'r') as f:
            fixed = f.read()
    except:
        fixed = code

    # Parse errors from report
    for line in report.splitlines():
        if line.startswith("ERROR") or line.startswith("SYNTAX") or line.startswith("WARNING"):
            errors += line + "\n"

    return errors.strip(), fixed.strip(), report.strip()

# ── Helper: ask Groq AI ──
def ask_groq(original_code, errors, rule_fix):
    if not errors:
        errors = "No errors detected by compiler."

    prompt = f"""You are an expert C programming tutor helping beginners fix their code.

A compiler analyzed this C code and found the following issues:

ERRORS DETECTED BY COMPILER:
{errors}

ORIGINAL C CODE:
{original_code}

RULE-BASED FIX ALREADY APPLIED BY COMPILER:
{rule_fix}

Please do the following:
1. Provide a fully corrected version of the C code
2. Explain each error in simple beginner-friendly language
3. Format your response exactly like this:

CORRECTED CODE:
<paste only the corrected C code here, no markdown>

EXPLANATION:
<explain each error and fix in simple points>
"""

    response = client.chat.completions.create(
        model="llama-3.3-70b-versatile",
        messages=[{"role": "user", "content": prompt}],
        max_tokens=2048,
        temperature=0.3
    )
    return response.choices[0].message.content

# ── Routes ──
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/analyze', methods=['POST'])
def analyze():
    code = request.form.get('code', '')

    if not code.strip():
        return jsonify({'error': 'No code provided'}), 400

    # Step 1: Run compiler
    errors, rule_fix, full_report = run_compiler(code)

    # Step 2: Ask Groq AI
    try:
        ai_response = ask_groq(code, errors, rule_fix)
    except Exception as e:
        ai_response = f"AI Error: {str(e)}"

    # Step 3: Parse AI response
    ai_code        = ""
    ai_explanation = ""

    if "CORRECTED CODE:" in ai_response and "EXPLANATION:" in ai_response:
        parts          = ai_response.split("EXPLANATION:")
        ai_code        = parts[0].replace("CORRECTED CODE:", "").strip()
        ai_explanation = parts[1].strip()
    else:
        ai_code        = ai_response
        ai_explanation = "See corrected code above."

    return jsonify({
        'original'       : code,
        'errors'         : errors if errors else "No errors found!",
        'rule_fix'       : rule_fix,
        'ai_code'        : ai_code,
        'ai_explanation' : ai_explanation
    })

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
