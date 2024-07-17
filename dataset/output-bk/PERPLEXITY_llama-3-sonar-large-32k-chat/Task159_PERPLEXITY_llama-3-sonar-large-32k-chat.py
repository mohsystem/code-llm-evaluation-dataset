code here:
buffer_size = int(input("Enter the buffer size: "))
buffer = [0] * buffer_size
for i in range(buffer_size):
    buffer[i] = i
while True:
    index = int(input("Enter the index to read (or -1 to quit): "))
    if index == -1:
        break
    if index < 0 or index >= buffer_size:
        print("Invalid index")
    else:
        print("Buffer[{}] = {}".format(index, buffer[index]))