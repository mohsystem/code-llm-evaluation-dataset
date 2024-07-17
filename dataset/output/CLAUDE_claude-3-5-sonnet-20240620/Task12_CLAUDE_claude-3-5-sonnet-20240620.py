
def calculate_score(word):
    return sum(ord(c) - ord(\'a\') + 1 for c in word.lower())

input_string = input()
words = input_string.split()

highest_scoring_word = max(words, key=calculate_score)
print(highest_scoring_word)
