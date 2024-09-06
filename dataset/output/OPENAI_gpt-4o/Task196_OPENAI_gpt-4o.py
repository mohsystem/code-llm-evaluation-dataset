import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zero_count = 0
        self.even_count = 2
        self.odd_count = 1
        self.zero_lock = threading.Lock()
        self.even_lock = threading.Lock()
        self.odd_lock = threading.Lock()
        self.even_lock.acquire()
        self.odd_lock.acquire()

    def zero(self, printNumber):
        for i in range(1, self.n + 1):
            self.zero_lock.acquire()
            printNumber(0)
            if i % 2 == 0:
                self.even_lock.release()
            else:
                self.odd_lock.release()

    def even(self, printNumber):
        for i in range(1, self.n // 2 + 1):
            self.even_lock.acquire()
            printNumber(self.even_count)
            self.even_count += 2
            self.zero_lock.release()

    def odd(self, printNumber):
        for i in range(1, (self.n + 1) // 2 + 1):
            self.odd_lock.acquire()
            printNumber(self.odd_count)
            self.odd_count += 2
            self.zero_lock.release()

def printNumber(x):
    print(x, end='')

n = 5
zeroEvenOdd = ZeroEvenOdd(n)
threads = [
    threading.Thread(target=zeroEvenOdd.zero, args=(printNumber,)),
    threading.Thread(target=zeroEvenOdd.even, args=(printNumber,)),
    threading.Thread(target=zeroEvenOdd.odd, args=(printNumber,))
]

for t in threads:
    t.start()
for t in threads:
    t.join()