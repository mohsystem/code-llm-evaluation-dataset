import threading

class Counter:
    def __init__(self, max_counter):
        self.max_counter = max_counter
        self.current_counter = 0
        self.lock = threading.Lock()

    def access_resource(self, thread_id):
        with self.lock:
            if self.current_counter <= self.max_counter:
                self.current_counter += 1
                print(f'Thread {thread_id} is accessing the currentCounter at the moment.')

# Example usage
max_counter = 10
counter = Counter(max_counter)

# Create and start multiple threads
threads = []
for i in range(15):
    thread = threading.Thread(target=counter.access_resource, args=(i,))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()