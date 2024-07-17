import threading

class SharedResource:
    def __init__(self):
        self.current_counter = 0
        self.max_counter = 10
        self.lock = threading.Lock()

    def access_resource(self, thread_id):
        if self.current_counter <= self.max_counter:
            with self.lock:
                self.current_counter += 1
                print(f"Thread {thread_id} is accessing the currentCounter at the moment. Current counter value: {self.current_counter}")

def thread_safe_mechanism(shared_resource, thread_id):
    shared_resource.access_resource(thread_id)

if __name__ == "__main__":
    shared_resource = SharedResource()
    threads = []

    for i in range(1, 21):
        thread = threading.Thread(target=thread_safe_mechanism, args=(shared_resource, i))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()