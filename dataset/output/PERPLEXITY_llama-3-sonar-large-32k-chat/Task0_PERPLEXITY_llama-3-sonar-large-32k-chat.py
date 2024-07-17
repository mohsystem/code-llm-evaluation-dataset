import os
import threading

lock = threading.Lock()

def process_file(filename):
    with lock:
        print(f"Processing file: {filename}")
        # Simulate file processing
        import time
        time.sleep(1)

def main():
    files = os.listdir("files")
    threads = []

    for file in files:
        thread = threading.Thread(target=process_file, args=(file,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()