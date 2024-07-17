def high(x):
    words = x.split()
    scores = []
    for word in words:
        score = sum(ord(c) - 96 for c in word)
        scores.append(score)
    max_score = max(scores)
    max_index = scores.index(max_score)
    return words[max_index]