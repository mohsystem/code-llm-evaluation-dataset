import os

def main():
    upload_folder = "uploads"
    if not os.path.exists(upload_folder):
        os.makedirs(upload_folder)

    filename = input("Enter the filename (including extension): ")
    filepath = os.path.join(upload_folder, filename)

    try:
        with open(filepath, 'wb') as f:
            print(f"Uploading to {filepath}...")
            while True:
                chunk = input("Enter a chunk of data (or type 'EOF' to end): ")
                if chunk == 'EOF':
                    break
                f.write(chunk.encode('utf-8'))
        print("File uploaded successfully!")
    except Exception as e:
        print(f"Error uploading file: {e}")

if __name__ == "__main__":
    main()