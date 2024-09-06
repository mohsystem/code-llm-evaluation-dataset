import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.state = 0
        self.lock = threading.Condition()
    
    def zero(self, printNumber):
        for _ in range(self.n):
            with self.lock:
                while self.state != 0:
                    self.lock.wait()
                printNumber(0)
                if self.state == 0:
                    self.state = 1 if _ % 2 == 0 else 2
                self.lock.notify_all()
    
    def even(self, printNumber):
        for i in range(2, self.n + 1, 2):
            with self.lock:
                while self.state != 2:
                    self.lock.wait()
                printNumber(i)
                self.state = 0
                self.lock.notify_all()
    
    def odd(self, printNumber):
        for i in range(1, self.n + 1, 2):
            with self.lock:
                while self.state != 1:
                    self.lock.wait()
                printNumber(i)
                self.state = 0
                self.lock.notify_all()

def printNumber(x):
    print(x, end='')

zeroEvenOdd = ZeroEvenOdd(5)
threadA = threading.Thread(target=zeroEvenOdd.zero, args=(printNumber,))
threadB = threading.Thread(target=zeroEvenOdd.even, args=(printNumber,))
threadC = threading.Thread(target=zeroEvenOdd.odd, args=(printNumber,))

threadA.start()
threadB.start()
threadC.start()

threadA.join()
threadB.join()
threadC.join()