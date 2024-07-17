import threading

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.zero_turn = True
        self.even_turn = False
        self.lock = threading.Lock()
        self.zero_condition = threading.Condition(self.lock)
        self.even_condition = threading.Condition(self.lock)
        self.odd_condition = threading.Condition(self.lock)
        
    def zero(self, printNumber):
        for _ in range(self.n):
            with self.zero_condition:
                while not self.zero_turn:
                    self.zero_condition.wait()
                printNumber(0)
                self.zero_turn = False
                if _ % 2 == 0:
                    self.odd_condition.notify()
                else:
                    self.even_condition.notify()
                    
    def even(self, printNumber):
        for i in range(2, self.n + 1, 2):
            with self.even_condition:
                while self.zero_turn or not self.even_turn:
                    self.even_condition.wait()
                printNumber(i)
                self.even_turn = False
                self.zero_turn = True
                self.zero_condition.notify()
                
    def odd(self, printNumber):
        for i in range(1, self.n + 1, 2):
            with self.odd_condition:
                while self.zero_turn or self.even_turn:
                    self.odd_condition.wait()
                printNumber(i)
                self.even_turn = True
                self.zero_turn = True
                self.zero_condition.notify()

def printNumber(x):
    print(x, end='')

n = 5
zeroEvenOdd = ZeroEvenOdd(n)
t1 = threading.Thread(target=zeroEvenOdd.zero, args=(printNumber,))
t2 = threading.Thread(target=zeroEvenOdd.even, args=(printNumber,))
t3 = threading.Thread(target=zeroEvenOdd.odd, args=(printNumber,))
t1.start()
t2.start()
t3.start()
t1.join()
t2.join()
t3.join()