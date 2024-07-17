def to_jaden_case(phrase):
    if not phrase:
        return None
    return ' '.join(word.capitalize() for word in phrase.split())

# Add test cases here
print(to_jaden_case("How can mirrors be real if our eyes aren't real"))
print(to_jaden_case(""))
print(to_jaden_case(None))