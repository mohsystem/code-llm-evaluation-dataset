import os
import threading

lock = threading.Lock()

def process_file(file_name):
    with lock:
        print(f"Processing file: {file_name}")
        # Simulate file processing
        with open(file_name, 'r') as file:
            content = file.read()
            print(f"File content: {content}")
        print(f"Finished processing file: {file_name}")

def main():
    directory = "./files"
    files = os.listdir(directory)
    threads = []

    for file in files:
        file_path = os.path.join(directory, file)
        thread = threading.Thread(target=process_file, args=(file_path,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()