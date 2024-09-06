# Python code
class SensitiveData:
    def __init__(self):
        self.data = {}

    def store_data(self, key, value):
        self.data[key] = value

    def retrieve_data(self, key):
        return self.data.get(key, "Data not found")

# Example usage
sensitive_data = SensitiveData()
sensitive_data.store_data('credit_card', '1234-5678-9012-3456')
print(sensitive_data.retrieve_data('credit_card'))