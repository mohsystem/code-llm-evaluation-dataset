import threading
import time

class SharedResource:
    def __init__(self, max_counter):
        self.current_counter = 0
        self.max_counter = max_counter
        self.lock = threading.Lock()

    def access_resource(self, thread_id):
        while self.current_counter <= self.max_counter:
            with self.lock:
                self.current_counter += 1
                print(f"Thread {thread_id} is accessing the currentCounter: {self.current_counter}")
                time.sleep(0.1)  # simulate some work

def main():
    shared_resource = SharedResource(5)
    thread1 = threading.Thread(target=shared_resource.access_resource, args=(1,))
    thread2 = threading.Thread(target=shared_resource.access_resource, args=(2,))
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()

if __name__ == "__main__":
    main()