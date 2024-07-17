import threading

currentCounter = 0
maxCounter = 5
lock = threading.Lock()

def accessResource(threadId):
    global currentCounter
    if currentCounter <= maxCounter:
        with lock:
            if currentCounter <= maxCounter:
                currentCounter += 1
                print(f"Thread {threadId} is accessing currentCounter: {currentCounter}")

thread1 = threading.Thread(target=accessResource, args=(1,))
thread2 = threading.Thread(target=accessResource, args=(2,))

thread1.start()
thread2.start()

thread1.join()
thread2.join()