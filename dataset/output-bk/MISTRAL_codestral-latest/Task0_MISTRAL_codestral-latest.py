import os
import threading

semaphore = threading.Semaphore()

def process_file(filename):
    semaphore.acquire()
    # Process the file here
    semaphore.release()

def process_files(path):
    for filename in os.listdir(path):
        threading.Thread(target=process_file, args=(filename,)).start()