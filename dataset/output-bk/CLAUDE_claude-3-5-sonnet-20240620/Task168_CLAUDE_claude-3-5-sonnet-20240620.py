
def tweakLetters(word, arr):
    result = ""
    for i in range(len(word)):
        char = word[i]
        if i < len(arr):
            char = chr((ord(char) - 97 + arr[i]) % 26 + 97)
        result += char
    return result

# Test cases
print(tweakLetters("apple", [0, 1, -1, 0, -1]))
print(tweakLetters("many", [0, 0, 0, -1]))
print(tweakLetters("rhino", [1, 1, 1, 1, 1]))
