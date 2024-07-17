def high(s):
    words = s.split(' ')
    max_word = max(words, key=lambda word: sum(ord(c) - 96 for c in word))
    return max_word