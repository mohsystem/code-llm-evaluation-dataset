
import os

def upload_file():
    filename = input("Enter the filename to upload: ")
    if os.path.exists(filename):
        with open(filename, \'rb\') as file:
            content = file.read()
        print(f"File \'{filename}\' uploaded successfully.")
        print(f"File size: {len(content)} bytes")
    else:
        print(f"File \'{filename}\' not found.")

if __name__ == "__main__":
    upload_file()
