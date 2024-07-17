buffer = bytearray(10)
print("Enter a string: ")
input_bytes = input().encode()
if len(input_bytes) > len(buffer):
    print("Input too large for buffer.")
else:
    buffer[:len(input_bytes)] = input_bytes
    print("Buffer contents:", buffer.decode())