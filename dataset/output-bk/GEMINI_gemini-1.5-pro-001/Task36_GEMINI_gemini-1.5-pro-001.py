file_path = input("Enter the file path: ")

try:
    with open(file_path, 'r') as file:
        for line in file:
            print(line, end='')
except FileNotFoundError:
    print("Error: File not found.")
except Exception as e:
    print(f"An error occurred: {e}")