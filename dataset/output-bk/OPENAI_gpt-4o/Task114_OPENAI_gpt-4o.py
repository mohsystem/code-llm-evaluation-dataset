# Python
def python_string_operations():
    str1 = "Hello"
    str2 = "World"
    copied_str = str1[:]
    concatenated_str = str1 + " " + str2
    manipulated_str = str1[::-1] + " " + str2.upper()
    print("Python - Copied:", copied_str)
    print("Python - Concatenated:", concatenated_str)
    print("Python - Manipulated:", manipulated_str)

python_string_operations()