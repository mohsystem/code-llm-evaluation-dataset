def distinct_concatenations(text):
    seen = set()
    length = len(text)
    for i in range(length):
        for j in range(i + 1, length + 1):
            sub = text[i:j]
            if len(sub) % 2 == 0:
                half_len = len(sub) // 2
                if sub[:half_len] == sub[half_len:]:
                    seen.add(sub)
    return len(seen)

# Example usage
text = "abcabcabc"
print(distinct_concatenations(text))  # Output: 3

text = "leetcodeleetcode"
print(distinct_concatenations(text))  # Output: 2