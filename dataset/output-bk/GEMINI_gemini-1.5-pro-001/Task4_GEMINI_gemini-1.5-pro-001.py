def is_isogram(string: str) -> bool:
    """Determine if a string is an isogram (case-insensitive).

    An isogram is a word or phrase without repeating letters.
    Empty strings are considered isograms.
    """
    seen = set()
    for char in string.lower():
        if char in seen:
            return False
        seen.add(char)
    return True
    
print(is_isogram("Dermatoglyphics"))
print(is_isogram("aba"))
print(is_isogram("moOse"))