
class BitFields:
    def __init__(self):
        self._data = 0

    @property
    def field1(self):
        return self._data & 0b11

    @field1.setter
    def field1(self, value):
        self._data = (self._data & ~0b11) | (value & 0b11)

    @property
    def field2(self):
        return (self._data >> 2) & 0b111

    @field2.setter
    def field2(self, value):
        self._data = (self._data & ~(0b111 << 2)) | ((value & 0b111) << 2)

    @property
    def field3(self):
        return (self._data >> 5) & 0b1

    @field3.setter
    def field3(self, value):
        self._data = (self._data & ~(0b1 << 5)) | ((value & 0b1) << 5)
