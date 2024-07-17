BUFFER_SIZE = 10

print("Enter a string: ")
input_str = input()

if len(input_str) > BUFFER_SIZE:
    print("Input is too long for the buffer.")
else:
    buffer = bytearray(BUFFER_SIZE)
    buffer[:len(input_str)] = input_str.encode()
    print("Input stored in buffer: ", buffer.decode())