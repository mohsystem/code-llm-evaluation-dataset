def tweak_letters(s, tweaks):
    result = ""
    for i in range(len(s)):
        char_code = ord(s[i]) + tweaks[i]
        if char_code < 97:
            char_code += 26
        elif char_code > 122:
            char_code -= 26
        result += chr(char_code)
    return result