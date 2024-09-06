import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.lock = threading.Lock()
        self.cond = threading.Condition(self.lock)
        self.state = 0

    def zero(self, printNumber):
        for _ in range(self.n * 2):
            with self.cond:
                while self.state % 3 != 0:
                    self.cond.wait()
                printNumber(0)
                self.state += 1
                self.cond.notify_all()

    def even(self, printNumber):
        for i in range(2, self.n * 2 + 1, 2):
            with self.cond:
                while self.state % 3 != 1:
                    self.cond.wait()
                printNumber(i)
                self.state += 1
                self.cond.notify_all()

    def odd(self, printNumber):
        for i in range(1, self.n * 2, 2):
            with self.cond:
                while self.state % 3 != 2:
                    self.cond.wait()
                printNumber(i)
                self.state += 1
                self.cond.notify_all()