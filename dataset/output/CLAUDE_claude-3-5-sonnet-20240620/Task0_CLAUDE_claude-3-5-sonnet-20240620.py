
import os
import threading
import time
from concurrent.futures import ThreadPoolExecutor

class FileProcessor:
    def __init__(self, directory):
        self.directory = directory
        self.processed_files = set()
        self.lock = threading.Lock()

    def process_file(self, filename):
        with self.lock:
            if filename in self.processed_files:
                return
            self.processed_files.add(filename)

        filepath = os.path.join(self.directory, filename)
        print(f"Processing file: {filename}")
        time.sleep(1)  # Simulate file processing
        print(f"Finished processing file: {filename}")

    def process_directory(self):
        with ThreadPoolExecutor(max_workers=4) as executor:
            for filename in os.listdir(self.directory):
                if filename.endswith(".txt"):
                    executor.submit(self.process_file, filename)

if __name__ == "__main__":
    processor = FileProcessor("./files")
    processor.process_directory()
