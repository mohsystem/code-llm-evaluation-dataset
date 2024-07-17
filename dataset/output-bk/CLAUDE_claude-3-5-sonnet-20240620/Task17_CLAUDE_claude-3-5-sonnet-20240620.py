
def to_jaden_case(string):
    if not string:
        return ""
    return " ".join(word.capitalize() for word in string.split())
