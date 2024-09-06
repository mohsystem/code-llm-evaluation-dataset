class BitFields:
    def __init__(self, a=0, b=0, c=0):
        self.a = a  # size: 1 bit
        self.b = b  # size: 2 bits
        self.c = c  # size: 3 bits

    def display(self):
        print(f'a: {self.a}, b: {self.b}, c: {self.c}')

bit_fields = BitFields(1, 2, 5)
bit_fields.display()