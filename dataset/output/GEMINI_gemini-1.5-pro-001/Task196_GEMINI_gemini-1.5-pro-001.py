class ZeroEvenOdd:

    
    def __init__(self, n):
        self.n = n
        self.zero_turn = True
        self.even_turn = False
        self.odd_turn = False

    
    def zero(self, printNumber):
        for i in range(1, self.n+1):
            while not self.zero_turn:
                pass
            printNumber(0)
            if i%2 == 0:
                self.even_turn = True
            else:
                self.odd_turn = True
            self.zero_turn = False

    
    def even(self, printNumber):
        for i in range(2, self.n+1, 2):
            while not self.even_turn:
                pass
            printNumber(i)
            self.zero_turn = True
            self.even_turn = False

    
    def odd(self, printNumber):
        for i in range(1, self.n+1, 2):
            while not self.odd_turn:
                pass
            printNumber(i)
            self.odd_turn = False
            self.zero_turn = True