import threading

currentCounter = 0
maxCounter = 5
lock = threading.Lock()

def access_resource(thread_id):
    global currentCounter
    if currentCounter <= maxCounter:
        with lock:
            if currentCounter < maxCounter:
                currentCounter += 1
                print(f"Thread {thread_id} is accessing currentCounter: {currentCounter}")

for i in range(10):
    thread = threading.Thread(target=access_resource, args=(i,))
    thread.start()