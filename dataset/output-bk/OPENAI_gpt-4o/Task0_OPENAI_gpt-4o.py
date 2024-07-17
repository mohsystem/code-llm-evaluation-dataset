import os
import threading
import time
from concurrent.futures import ThreadPoolExecutor

lock = threading.Lock()

def process_file(filename):
    with lock:
        print(f"Processing {filename} by {threading.current_thread().name}")
        time.sleep(1)  # Simulate file processing

def main():
    shared_directory = "shared_directory"
    with ThreadPoolExecutor(max_workers=10) as executor:
        for root, _, files in os.walk(shared_directory):
            for file in files:
                executor.submit(process_file, os.path.join(root, file))

if __name__ == "__main__":
    main()