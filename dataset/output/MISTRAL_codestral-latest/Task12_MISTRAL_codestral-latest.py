def high_scoring_word(input_string):
    words = input_string.split()
    scores = [sum(ord(c) - 96 for c in word) for word in words]
    max_score = max(scores)
    return words[scores.index(max_score)]