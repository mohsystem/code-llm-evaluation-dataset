code here:
buffer_size = 10
buffer = [None] * buffer_size
index = 0

while True:
    user_input = input("Enter a value (or 'quit' to exit): ")
    if user_input.lower() == 'quit':
        break
    if index < buffer_size:
        buffer[index] = user_input
        index += 1
    else:
        print("Buffer is full. Oldest value will be replaced.")
        buffer.pop(0)
        buffer.append(user_input)
    print("Buffer:", buffer)