def number(lines):
    numbered_lines = []
    for i, line in enumerate(lines, start=1):
        numbered_lines.append(f"{i}: {line}")
    return numbered_lines