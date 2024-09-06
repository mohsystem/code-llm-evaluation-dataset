def tweakLetters(word, tweaks):
    return ''.join([chr(ord(word[i]) + tweaks[i]) for i in range(len(word))])