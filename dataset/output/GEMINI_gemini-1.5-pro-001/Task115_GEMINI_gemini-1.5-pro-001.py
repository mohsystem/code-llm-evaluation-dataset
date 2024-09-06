class PackedData:
    def __init__(self, value):
        self.value = value
        self.flag1 = (value >> 0) & 0x1
        self.flag2 = (value >> 1) & 0x3
        self.value2 = (value >> 3) & 0x1F