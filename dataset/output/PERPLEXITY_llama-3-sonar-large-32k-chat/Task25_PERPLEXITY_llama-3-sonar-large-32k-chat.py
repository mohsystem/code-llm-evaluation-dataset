def number_lines(lines):
    return [f"{i + 1}: {line}" for i, line in enumerate(lines)]

lines = ["a", "b", "c"]
for line in number_lines(lines):
    print(line)