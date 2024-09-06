def high(x):
    words = x.split()
    highest_score = 0
    highest_word = ""
    for word in words:
        score = 0
        for letter in word:
            score += ord(letter) - 96
        if score > highest_score:
            highest_score = score
            highest_word = word
    return highest_word