class SensitiveData:
    def __init__(self, data):
        self.__data = data

    def get_data(self):
        return self.__data

data = SensitiveData("1234-5678-9012-3456")
print(data.get_data())