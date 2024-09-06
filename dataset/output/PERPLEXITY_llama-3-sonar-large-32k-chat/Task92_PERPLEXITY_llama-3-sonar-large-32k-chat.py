import threading

maxCounter = 5
currentCounter = 0
lock = threading.Lock()

def access_resource(thread_name):
    global currentCounter
    while currentCounter <= maxCounter:
        with lock:
            if currentCounter <= maxCounter:
                currentCounter += 1
                print(f"Thread {thread_name} is accessing the currentCounter at {currentCounter}")
            else:
                break

threads = []
for i in range(5):
    t = threading.Thread(target=access_resource, args=(i,))
    threads.append(t)
    t.start()

for t in threads:
    t.join()