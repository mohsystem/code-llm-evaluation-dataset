def number(lines):
    return [f"{i + 1}: {line}" for i, line in enumerate(lines)]

if __name__ == "__main__":
    lines = ["a", "b", "c"]
    print(number(lines))