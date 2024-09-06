def distinct_aa_substrings(text):
    distinct_substrings = set()
    n = len(text)
    
    for i in range(n):
        for j in range(i+1, n, 2):
            a = text[i:(i+j+1)//2]
            b = text[(i+j+1)//2:j+1]
            if a == b:
                distinct_substrings.add(text[i:j+1])
    
    return len(distinct_substrings)

# Example usage:
text = "abcabcabc"
print(distinct_aa_substrings(text))

text = "leetcodeleetcode"
print(distinct_aa_substrings(text))