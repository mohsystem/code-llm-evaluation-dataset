# Python
class CryptoKeyManager:
    def __init__(self):
        self.keys = {}

    def add_key(self, key_name, key_value):
        self.keys[key_name] = key_value

    def get_key(self, key_name):
        return self.keys.get(key_name, None)

    def remove_key(self, key_name):
        if key_name in self.keys:
            del self.keys[key_name]