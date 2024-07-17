# Python
def is_pangram(sentence):
    return len({ch.lower() for ch in sentence if ch.isalpha()}) == 26

sentence = "The quick brown fox jumps over the lazy dog"
print(is_pangram(sentence))