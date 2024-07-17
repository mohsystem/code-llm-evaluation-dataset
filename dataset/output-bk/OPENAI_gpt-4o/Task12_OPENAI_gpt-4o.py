def word_score(word):
    return sum(ord(c) - ord('a') + 1 for c in word)

def highest_scoring_word(s):
    return max(s.split(), key=word_score)

input_string = "example input sentence"
print(highest_scoring_word(input_string))