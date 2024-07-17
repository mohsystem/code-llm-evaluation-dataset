def main():
    file_name = input("Enter file name: ")
    try:
        with open(file_name, 'r') as file:
            for line in file:
                print(line, end='')
    except IOError as e:
        print("Error reading file:", e)

if __name__ == "__main__":
    main()