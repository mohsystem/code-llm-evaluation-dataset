class BitFields:
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0

    def setA(self, val):
        self.a = val

    def setB(self, val):
        self.b = val

    def setC(self, val):
        self.c = val

    def print(self):
        print("a:", self.a)
        print("b:", self.b)
        print("c:", self.c)

bf = BitFields()
bf.setA(1)
bf.setB(2)
bf.setC(3)
bf.print()