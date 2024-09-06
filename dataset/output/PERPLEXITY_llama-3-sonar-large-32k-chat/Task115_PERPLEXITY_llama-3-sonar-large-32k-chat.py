class BitFields:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

bf = BitFields(1, 2, 3)
print(bf.a, bf.b, bf.c)