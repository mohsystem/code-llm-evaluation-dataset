def tweakLetters(word, tweaks):
    return ''.join(chr((ord(c) - 97 + t) % 26 + 97) for c, t in zip(word, tweaks))