class BitFields:
    def __init__(self, field1, field2, field3):
        self.field1 = field1 & 1
        self.field2 = field2 & 3
        self.field3 = field3 & 7

    def display_fields(self):
        print(f"Field1: {self.field1}")
        print(f"Field2: {self.field2}")
        print(f"Field3: {self.field3}")

bf = BitFields(1, 2, 5)
bf.display_fields()