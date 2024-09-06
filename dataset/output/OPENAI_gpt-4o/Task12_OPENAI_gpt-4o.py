def high(input_string):
    words = input_string.split()
    max_score = 0
    best_word = ""
    
    for word in words:
        score = sum(ord(char) - 96 for char in word)
        if score > max_score:
            max_score = score
            best_word = word
            
    return best_word

input_string = "abad test example"
print(high(input_string))