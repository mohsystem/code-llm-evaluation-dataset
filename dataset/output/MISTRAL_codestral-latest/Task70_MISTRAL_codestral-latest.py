import sys

if len(sys.argv) > 1:
    try:
        with open(sys.argv[1], 'r') as file:
            print(file.read())
    except IOError:
        print("Unable to open the file.")
else:
    print("Please provide a file path as an argument.")