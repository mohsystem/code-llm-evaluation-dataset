def run_Python(bufferSize, input):
    buffer = [''] * bufferSize
    print("Enter input (Python): ", end='')
    user_input = input[:bufferSize]
    buffer[:len(user_input)] = user_input
    print("Buffer contents (Python):", ''.join(buffer))

bufferSize = 10
user_input = input("Input: ")
run_Python(bufferSize, list(user_input))