def number_lines(lines):
    return [f"{i+1}: {line}" for i, line in enumerate(lines)]

lines = ["a", "b", "c"]
print(number_lines(lines))