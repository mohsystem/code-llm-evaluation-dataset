def is_isogram(string):
    string = string.lower()
    return len(string) == len(set(string))