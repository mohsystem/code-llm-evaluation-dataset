def tweak_letters(s, arr):
    return ''.join(chr(((ord(s[i]) - ord('a') + arr[i]) % 26) + ord('a')) for i in range(len(s)))

print(tweak_letters("apple", [0, 1, -1, 0, -1]))  # "aqold"
print(tweak_letters("many", [0, 0, 0, -1]))      # "manx"
print(tweak_letters("rhino", [1, 1, 1, 1, 1]))    # "sijop"