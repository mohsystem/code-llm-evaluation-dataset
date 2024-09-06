def concatenate_strings():
    num_strings = int(input("Enter the number of strings: "))
    result = ""
    for i in range(num_strings):
        result += input("Enter string {}: ".format(i+1)) + " "
    print("Concatenated string: ", result)

concatenate_strings()