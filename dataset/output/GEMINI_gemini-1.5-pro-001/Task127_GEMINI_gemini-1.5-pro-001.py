import os
import tempfile

def handle_file_transfer(source_file):
    try:
        with open(source_file, 'rb') as infile:
            with tempfile.NamedTemporaryFile(delete=False, mode='wb') as outfile:
                outfile.write(infile.read())
        print(f"File copied to temporary location: {outfile.name}")
    except FileNotFoundError:
        print(f"Error: File not found: {source_file}")
    except IOError as e:
        print(f"Error during file operation: {e}")

if __name__ == "__main__":
    filename = input("Enter the file name: ")
    handle_file_transfer(filename)