def calculate_score(report_text, code):
    score = 100
    deductions = []
    lines = code.splitlines()
    total_lines = max(len(lines), 1)

    syntax_errors  = 0
    errors         = 0
    warnings       = 0
    unused_vars    = 0
    uninit_vars    = 0
    duplicate_vars = 0

    for line in report_text.splitlines():
        line = line.strip()
        if line.startswith("SYNTAX ERROR"):
            syntax_errors += 1
        elif line.startswith("ERROR"):
            if "already declared" in line:
                duplicate_vars += 1
            else:
                errors += 1
        elif line.startswith("WARNING"):
            if "never used" in line:
                unused_vars += 1
            elif "before initialization" in line:
                uninit_vars += 1
            else:
                warnings += 1

    # deduct points
    if syntax_errors > 0:
        pts = min(syntax_errors * 10, 30)
        score -= pts
        deductions.append(f"Syntax errors: -{pts} pts ({syntax_errors} found)")

    if errors > 0:
        pts = min(errors * 8, 25)
        score -= pts
        deductions.append(f"Semantic errors: -{pts} pts ({errors} found)")

    if duplicate_vars > 0:
        pts = min(duplicate_vars * 5, 15)
        score -= pts
        deductions.append(f"Duplicate declarations: -{pts} pts ({duplicate_vars} found)")

    if uninit_vars > 0:
        pts = min(uninit_vars * 5, 15)
        score -= pts
        deductions.append(f"Uninitialized variables: -{pts} pts ({uninit_vars} found)")

    if unused_vars > 0:
        pts = min(unused_vars * 3, 10)
        score -= pts
        deductions.append(f"Unused variables: -{pts} pts ({unused_vars} found)")

    # check code style
    has_comments = "/*" in code or "//" in code
    if not has_comments:
        score -= 5
        deductions.append("No comments found: -5 pts")

    has_main = "main" in code
    if not has_main:
        score -= 5
        deductions.append("No main function: -5 pts")

    score = max(score, 0)

    # grade
    if score >= 90:
        grade = "A"
        grade_color = "green"
        message = "Excellent! Your code is very clean."
    elif score >= 75:
        grade = "B"
        grade_color = "cyan"
        message = "Good code with minor issues."
    elif score >= 60:
        grade = "C"
        grade_color = "amber"
        message = "Average code. Several issues to fix."
    elif score >= 40:
        grade = "D"
        grade_color = "orange"
        message = "Poor code quality. Many issues found."
    else:
        grade = "F"
        grade_color = "red"
        message = "Critical issues found. Major fixes needed."

    return {
        "score":       score,
        "grade":       grade,
        "grade_color": grade_color,
        "message":     message,
        "deductions":  deductions,
        "breakdown": {
            "syntax":    max(100 - syntax_errors * 10, 0),
            "semantics": max(100 - errors * 10, 0),
            "variables": max(100 - (uninit_vars + duplicate_vars) * 10, 0),
            "style":     100 if has_comments else 50,
            "structure": 100 if has_main else 0
        }
    }