size = int(input("Enter the size of the buffer: "))
buffer = [0] * size

index = int(input("Enter the index to read from the buffer: "))

if index >= 0 and index < size:
    print("Value at index", index, ":", buffer[index])
else:
    print("Invalid index.")