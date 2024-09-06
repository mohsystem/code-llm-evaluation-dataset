import threading
import os

file_locks = {}

def process_file(file_path):
    with file_locks[file_path]:
        # Simulate file processing
        print(f"Thread {threading.current_thread().name} is processing file: {file_path}")
        # Add your file processing logic here

def main():
    directory = 'path/to/your/directory' # Replace with your directory path
    for filename in os.listdir(directory):
        file_path = os.path.join(directory, filename)
        if os.path.isfile(file_path):
            file_locks[file_path] = threading.Lock()
            thread = threading.Thread(target=process_file, args=(file_path,))
            thread.start()

if __name__ == "__main__":
    main()