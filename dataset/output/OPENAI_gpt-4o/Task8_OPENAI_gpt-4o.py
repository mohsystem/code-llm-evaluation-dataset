def find_missing_letter(chars):
    for i in range(len(chars) - 1):
        if ord(chars[i + 1]) != ord(chars[i]) + 1:
            return chr(ord(chars[i]) + 1)
    raise ValueError("No missing letter detected.")

if __name__ == "__main__":
    array1 = ['a', 'b', 'c', 'd', 'f']
    array2 = ['O', 'Q', 'R', 'S']
    
    print(find_missing_letter(array1)) # Output: e
    print(find_missing_letter(array2)) # Output: P