# Python
def reverse_words(input):
    return ' '.join([word[::-1] if len(word) >= 5 else word for word in input.split()])

input = "Hey fellow warriors"
print(reverse_words(input))