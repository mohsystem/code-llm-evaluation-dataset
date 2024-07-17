def check(sentence):
    alphabet = set("abcdefghijklmnopqrstuvwxyz")
    sentence = set(c for c in sentence.lower() if c.isalpha())
    return alphabet.issubset(sentence)

print(check("The quick brown fox jumps over the lazy dog")) # True
print(check("Hello World")) # False