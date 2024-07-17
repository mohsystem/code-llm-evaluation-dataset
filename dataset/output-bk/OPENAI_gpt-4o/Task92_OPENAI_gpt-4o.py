import threading

class Counter:
    def __init__(self, max_counter):
        self.current_counter = 0
        self.max_counter = max_counter
        self.lock = threading.Lock()

    def increment(self, thread_id):
        while True:
            with self.lock:
                if self.current_counter <= self.max_counter:
                    print(f'Thread-{thread_id} accessing currentCounter: {self.current_counter}')
                    self.current_counter += 1
                else:
                    break

if __name__ == "__main__":
    max_counter = 10
    counter = Counter(max_counter)
    threads = []
    for i in range(5):
        t = threading.Thread(target=counter.increment, args=(i+1,))
        threads.append(t)
        t.start()
    for t in threads:
        t.join()