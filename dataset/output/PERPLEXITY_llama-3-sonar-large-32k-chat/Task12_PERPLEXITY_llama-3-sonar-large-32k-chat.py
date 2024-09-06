def high(s):
    words = s.split(' ')
    max_score = 0
    max_word = ''
    for word in words:
        score = sum(ord(c) - 96 for c in word)
        if score > max_score:
            max_score = score
            max_word = word
    return max_word