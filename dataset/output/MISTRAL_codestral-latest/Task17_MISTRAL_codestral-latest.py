# Python
def toJadenCase(phrase):
    return ' '.join(word.capitalize() for word in phrase.split())

print(toJadenCase("How can mirrors be real if our eyes aren't real"))