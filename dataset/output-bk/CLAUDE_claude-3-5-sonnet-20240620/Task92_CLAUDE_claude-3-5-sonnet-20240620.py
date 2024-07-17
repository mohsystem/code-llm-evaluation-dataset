
import threading

max_counter = 10
current_counter = 0
lock = threading.Lock()

def counter_thread():
    global current_counter
    while True:
        if current_counter <= max_counter:
            with lock:
                if current_counter <= max_counter:
                    current_counter += 1
                    print(f"Thread {threading.current_thread().ident} accessing counter: {current_counter}")
        else:
            break

if __name__ == "__main__":
    threads = []
    for _ in range(5):
        t = threading.Thread(target=counter_thread)
        threads.append(t)
        t.start()

    for t in threads:
        t.join()
