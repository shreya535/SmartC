import re

EXPLANATIONS = {
    r"undeclared variable '(\w+)'": lambda m: {
        "type": "ERROR",
        "title": "Undeclared Variable",
        "what": f"You used '{m.group(1)}' but never declared it.",
        "why": "In C every variable must be declared with its type before use.",
        "fix": f"Add 'int {m.group(1)} = 0;' before you use it.",
        "example_wrong": f"{m.group(1)} = 10;",
        "example_right": f"int {m.group(1)} = 10;"
    },

    r"variable '(\w+)' used before initialization": lambda m: {
        "type": "WARNING",
        "title": "Uninitialized Variable",
        "what": f"'{m.group(1)}' exists but has no value when used.",
        "why": "Uninitialized variables contain garbage values causing unpredictable bugs.",
        "fix": f"Change 'int {m.group(1)};' to 'int {m.group(1)} = 0;'",
        "example_wrong": f"int {m.group(1)};  use({m.group(1)});",
        "example_right": f"int {m.group(1)} = 0;  use({m.group(1)});"
    },

    r"variable '(\w+)' already declared": lambda m: {
        "type": "ERROR",
        "title": "Duplicate Declaration",
        "what": f"'{m.group(1)}' is declared twice in the same scope.",
        "why": "C does not allow two variables with the same name in the same block.",
        "fix": f"Remove the second 'int {m.group(1)};' declaration.",
        "example_wrong": f"int {m.group(1)} = 5;  int {m.group(1)} = 10;",
        "example_right": f"int {m.group(1)} = 5;  {m.group(1)} = 10;"
    },

    r"'(\w+)' declared.*never used": lambda m: {
        "type": "WARNING",
        "title": "Unused Variable",
        "what": f"'{m.group(1)}' is declared but never used anywhere.",
        "why": "Unused variables waste memory and make code hard to read.",
        "fix": f"Either use '{m.group(1)}' somewhere or remove its declaration.",
        "example_wrong": f"int {m.group(1)} = 5;  /* never used */",
        "example_right": f"/* remove: int {m.group(1)} = 5; */"
    },

    r"SYNTAX ERROR at line (\d+)": lambda m: {
        "type": "SYNTAX",
        "title": "Syntax Error",
        "what": f"Code structure is wrong at line {m.group(1)}.",
        "why": "The compiler cannot understand your code structure.",
        "fix": "Check for missing ; } ) on this line or the line before.",
        "example_wrong": "printf('hello')",
        "example_right": "printf('hello');"
    },

    r"missing return": lambda m: {
        "type": "ERROR",
        "title": "Missing Return Statement",
        "what": "Your function does not return a value.",
        "why": "Functions declared with a return type must return a value.",
        "fix": "Add 'return 0;' at the end of your function.",
        "example_wrong": "int main() { printf('hi'); }",
        "example_right": "int main() { printf('hi'); return 0; }"
    }
}

def explain_error(error_line):
    for pattern, generator in EXPLANATIONS.items():
        match = re.search(pattern, error_line)
        if match:
            return generator(match)
    return {
        "type": "UNKNOWN",
        "title": "Compiler Error",
        "what": error_line,
        "why": "An error was detected by the compiler.",
        "fix": "Review the indicated line carefully.",
        "example_wrong": "",
        "example_right": ""
    }

def process_report(report_text):
    results = []
    for line in report_text.splitlines():
        line = line.strip()
        if not line:
            continue
        if (line.startswith("ERROR") or
            line.startswith("WARNING") or
            line.startswith("SYNTAX")):
            explanation = explain_error(line)
            explanation["original"] = line
            results.append(explanation)
    return results