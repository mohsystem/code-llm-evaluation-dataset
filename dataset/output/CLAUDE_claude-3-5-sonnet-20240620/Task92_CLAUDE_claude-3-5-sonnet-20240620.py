
import threading

class SharedResource:
    def __init__(self, max_counter):
        self.current_counter = 0
        self.max_counter = max_counter
        self.lock = threading.Lock()

def access_resource(thread_id, shared_resource):
    while True:
        if shared_resource.current_counter <= shared_resource.max_counter:
            with shared_resource.lock:
                if shared_resource.current_counter <= shared_resource.max_counter:
                    shared_resource.current_counter += 1
                    print(f"Thread {thread_id} accessing. Current counter: {shared_resource.current_counter}")
                    if shared_resource.current_counter > shared_resource.max_counter:
                        break
        else:
            break

def main():
    max_counter = 10
    num_threads = 5
    shared_resource = SharedResource(max_counter)

    threads = []
    for i in range(num_threads):
        thread = threading.Thread(target=access_resource, args=(i, shared_resource))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

if __name__ == "__main__":
    main()
