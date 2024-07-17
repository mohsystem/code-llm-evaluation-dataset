
BUFFER_SIZE = 20

buffer = [\'\'] * BUFFER_SIZE

input_string = input(f"Enter a string (max {BUFFER_SIZE} characters):\
")

length = min(len(input_string), BUFFER_SIZE)
buffer[:length] = input_string[:length]

print("Buffer contents:")
print(\'\'.join(buffer[:length]))
