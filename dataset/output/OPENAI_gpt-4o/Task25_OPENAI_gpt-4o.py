def number(lines):
    return [f"{i + 1}: {line}" for i, line in enumerate(lines)]

# Test
print(number([]))  # []
print(number(["a", "b", "c"]))  # ["1: a", "2: b", "3: c"]