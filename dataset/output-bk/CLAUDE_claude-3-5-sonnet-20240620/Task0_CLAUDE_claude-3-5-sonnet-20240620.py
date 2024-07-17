
import os
import time
import threading
from concurrent.futures import ThreadPoolExecutor

DIRECTORY_PATH = "shared_directory"
NUM_THREADS = 4

def process_file(file_path):
    print(f"Processing file: {os.path.basename(file_path)} by thread: {threading.current_thread().name}")
    # Simulating file processing
    time.sleep(2)
    # Delete the processed file
    os.remove(file_path)

def process_files():
    while True:
        with threading.Lock():
            files = [f for f in os.listdir(DIRECTORY_PATH) if os.path.isfile(os.path.join(DIRECTORY_PATH, f))]
            if files:
                file_to_process = os.path.join(DIRECTORY_PATH, files[0])
            else:
                file_to_process = None

        if file_to_process:
            process_file(file_to_process)
        else:
            time.sleep(1)

def main():
    os.makedirs(DIRECTORY_PATH, exist_ok=True)

    with ThreadPoolExecutor(max_workers=NUM_THREADS) as executor:
        futures = [executor.submit(process_files) for _ in range(NUM_THREADS)]

        for future in futures:
            future.result()

if __name__ == "__main__":
    main()
