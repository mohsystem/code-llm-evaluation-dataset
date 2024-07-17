
def read_file(filename):
    try:
        with open(filename, \'r\') as file:
            for line in file:
                print(line, end=\'\')
    except IOError as e:
        print(f"An error occurred while reading the file: {e}")

if __name__ == "__main__":
    filename = input("Enter the file name: ")
    read_file(filename)
