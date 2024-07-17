
class Flags:
    def __init__(self):
        self._data = 0

    def is_flag1(self):
        return bool(self._data & 1)

    def is_flag2(self):
        return bool(self._data & 2)

    def is_flag3(self):
        return bool(self._data & 4)

    def get_value(self):
        return (self._data >> 3) & 0x1F

    def set_flag1(self, value):
        self._data = (self._data | 1) if value else (self._data & ~1)

    def set_flag2(self, value):
        self._data = (self._data | 2) if value else (self._data & ~2)

    def set_flag3(self, value):
        self._data = (self._data | 4) if value else (self._data & ~4)

    def set_value(self, value):
        self._data = (self._data & 0x7) | ((value & 0x1F) << 3)

if __name__ == "__main__":
    flags = Flags()
    flags.set_flag1(True)
    flags.set_flag2(False)
    flags.set_flag3(True)
    flags.set_value(15)

    print("Flag1:", flags.is_flag1())
    print("Flag2:", flags.is_flag2())
    print("Flag3:", flags.is_flag3())
    print("Value:", flags.get_value())
