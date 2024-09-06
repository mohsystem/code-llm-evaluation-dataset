def tweakLetters(s, tweaks):
    result = ""
    for i in range(len(s)):
        char_code = ord(s[i]) + tweaks[i]
        result += chr(char_code)
    return result