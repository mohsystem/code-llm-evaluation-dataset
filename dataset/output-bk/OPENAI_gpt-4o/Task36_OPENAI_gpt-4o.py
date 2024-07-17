import sys

def read_file_in_python(file_name):
    try:
        with open(file_name, 'r') as file:
            for line in file:
                sys.stdout.write(line)
    except IOError as e:
        print(f"An error occurred: {e}")