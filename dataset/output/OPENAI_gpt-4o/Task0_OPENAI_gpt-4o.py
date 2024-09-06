import threading
import os

lock = threading.Lock()

def process_file(file_path):
    lock.acquire()
    try:
        with open(file_path, 'r') as file:
            data = file.read()
            # Process the file (example: print its contents)
            print(f"Processed by {threading.current_thread().name}: {data}")
    finally:
        lock.release()

def process_directory(directory_path):
    threads = []
    for file_name in os.listdir(directory_path):
        file_path = os.path.join(directory_path, file_name)
        if os.path.isfile(file_path):
            thread = threading.Thread(target=process_file, args=(file_path,))
            threads.append(thread)
            thread.start()
    for thread in threads:
        thread.join()

if __name__ == '__main__':
    directory = 'path_to_directory'
    process_directory(directory)