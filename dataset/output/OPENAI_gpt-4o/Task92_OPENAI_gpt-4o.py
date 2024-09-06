import threading

maxCounter = 10
currentCounter = 0
lock = threading.Lock()

def worker(thread_id):
    global currentCounter
    while True:
        with lock:
            if currentCounter <= maxCounter:
                print(f"Thread {thread_id} accessing currentCounter: {currentCounter}")
                currentCounter += 1
            else:
                break

threads = []
for i in range(5):
    t = threading.Thread(target=worker, args=(i,))
    threads.append(t)
    t.start()

for t in threads:
    t.join()