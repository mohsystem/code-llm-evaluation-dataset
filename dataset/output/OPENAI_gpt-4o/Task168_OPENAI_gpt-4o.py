def tweakLetters(txt, arr):
    return ''.join(chr(ord(c) + n) for c, n in zip(txt, arr))

print(tweakLetters("apple", [0, 1, -1, 0, -1]))
print(tweakLetters("many", [0, 0, 0, -1]))
print(tweakLetters("rhino", [1, 1, 1, 1, 1]))