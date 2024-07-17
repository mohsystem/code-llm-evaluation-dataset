import os

def upload_file(file_path):
    with open(file_path, 'rb') as f:
        file_content = f.read()
    with open('uploaded_' + os.path.basename(file_path), 'wb') as f:
        f.write(file_content)

file_path = input("Enter the file path: ")
upload_file(file_path)
print("File uploaded successfully!")