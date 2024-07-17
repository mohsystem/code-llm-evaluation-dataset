class BitFieldExample:
    def __init__(self, bitField):
        self.bitField = bitField

    def get_bit_field(self):
        return self.bitField

    def set_bit_field(self, bitField):
        self.bitField = bitField

    def get_bit(self, position):
        return ((self.bitField & (1 << position)) != 0)

    def set_bit(self, position, value):
        if value:
            self.bitField |= (1 << position)
        else:
            self.bitField &= ~(1 << position)