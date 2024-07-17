import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zero_turn = True
        self.even_turn = False
        self.odd_turn = False
        self.lock = threading.Condition()

    def zero(self, printNumber):
        for _ in range(self.n):
            with self.lock:
                while not self.zero_turn:
                    self.lock.wait()
                printNumber(0)
                self.zero_turn = False
                self.odd_turn = not self.odd_turn
                self.even_turn = not self.even_turn
                self.lock.notify_all()

    def even(self, printNumber):
        for i in range(2, self.n+1, 2):
            with self.lock:
                while not self.even_turn:
                    self.lock.wait()
                printNumber(i)
                self.even_turn = False
                self.zero_turn = True
                self.lock.notify_all()

    def odd(self, printNumber):
        for i in range(1, self.n+1, 2):
            with self.lock:
                while not self.odd_turn:
                    self.lock.wait()
                printNumber(i)
                self.odd_turn = False
                self.zero_turn = True
                self.lock.notify_all()

n = 5
zeo = ZeroEvenOdd(n)

def printNumber(x):
    print(x, end='')

threadA = threading.Thread(target=zeo.zero, args=(printNumber,))
threadB = threading.Thread(target=zeo.even, args=(printNumber,))
threadC = threading.Thread(target=zeo.odd, args=(printNumber,))

threadA.start()
threadB.start()
threadC.start()

threadA.join()
threadB.join()
threadC.join()