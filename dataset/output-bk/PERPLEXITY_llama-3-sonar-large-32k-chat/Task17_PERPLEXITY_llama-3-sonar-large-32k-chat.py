def to_jaden_case(phrase):
    if not phrase:
        return None
    words = phrase.split(' ')
    return ' '.join(word.capitalize() for word in words)

print(to_jaden_case("How can mirrors be real if our eyes aren't real"))