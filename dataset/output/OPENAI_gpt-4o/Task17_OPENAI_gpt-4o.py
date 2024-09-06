def to_jaden_case(string):
    if not string:
        return None
    return ' '.join(word.capitalize() for word in string.split())

# Example usage
print(to_jaden_case("How can mirrors be real if our eyes aren't real"))