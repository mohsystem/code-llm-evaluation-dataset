
import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zero_sem = threading.Semaphore(1)
        self.even_sem = threading.Semaphore(0)
        self.odd_sem = threading.Semaphore(0)
        self.current = 1

    def zero(self, printNumber):
        for _ in range(self.n):
            self.zero_sem.acquire()
            printNumber(0)
            if self.current % 2 == 0:
                self.even_sem.release()
            else:
                self.odd_sem.release()

    def even(self, printNumber):
        for _ in range(self.n // 2):
            self.even_sem.acquire()
            printNumber(self.current)
            self.current += 1
            self.zero_sem.release()

    def odd(self, printNumber):
        for _ in range((self.n + 1) // 2):
            self.odd_sem.acquire()
            printNumber(self.current)
            self.current += 1
            self.zero_sem.release()

# Example usage:
def printNumber(x):
    print(x, end='')

n = 5
zeo = ZeroEvenOdd(n)

threads = [
    threading.Thread(target=zeo.zero, args=(printNumber,)),
    threading.Thread(target=zeo.even, args=(printNumber,)),
    threading.Thread(target=zeo.odd, args=(printNumber,))
]

for t in threads:
    t.start()

for t in threads:
    t.join()
