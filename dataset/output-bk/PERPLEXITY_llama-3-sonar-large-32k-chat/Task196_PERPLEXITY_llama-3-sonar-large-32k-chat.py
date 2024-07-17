import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.lock = threading.Lock()
        self.cond = threading.Condition(self.lock)
        self.state = 0

    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for _ in range(self.n * 2):
            with self.cond:
                while self.state % 2 != 0:
                    self.cond.wait()
                printNumber(0)
                self.state += 1
                self.cond.notify_all()

    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(2, self.n * 2 + 1, 2):
            with self.cond:
                while self.state != i:
                    self.cond.wait()
                printNumber(i)
                self.state += 1
                self.cond.notify_all()

    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n * 2, 2):
            with self.cond:
                while self.state != i:
                    self.cond.wait()
                printNumber(i)
                self.state += 1
                self.cond.notify_all()