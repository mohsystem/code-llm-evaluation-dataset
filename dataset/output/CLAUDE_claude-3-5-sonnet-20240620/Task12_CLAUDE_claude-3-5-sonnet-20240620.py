
def high(x):
    words = x.split()
    max_score = 0
    max_word = ''
    
    for word in words:
        score = sum(ord(c) - 96 for c in word)
        if score > max_score:
            max_score = score
            max_word = word
    
    return max_word

# Example usage
print(high('man i need a taxi up to ubud'))  # Output: taxi
print(high('what time are we climbing up the volcano'))  # Output: volcano
print(high('take me to semynak'))  # Output: semynak
