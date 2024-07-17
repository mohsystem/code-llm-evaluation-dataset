def reverse_words(s):
    words = s.split()
    for i in range(len(words)):
        if len(words[i]) >= 5:
            words[i] = words[i][::-1]
    return ' '.join(words)

print(reverse_words("Hey fellow warriors"))
print(reverse_words("This is a test"))
print(reverse_words("This is another test"))