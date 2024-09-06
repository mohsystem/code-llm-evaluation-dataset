import hashlib
import os

class KeyManager:
    def __init__(self):
        self.keys = {}

    def generate_key(self, key_name):
        key = os.urandom(32)
        self.keys[key_name] = key
        return key

    def get_key(self, key_name):
        return self.keys.get(key_name)

    def delete_key(self, key_name):
        if key_name in self.keys:
            del self.keys[key_name]

    def hash_key(self, key_name):
        key = self.get_key(key_name)
        if key:
            return hashlib.sha256(key).hexdigest()
        else:
            return None

# Example usage
manager = KeyManager()
key_name = "my_key"
key = manager.generate_key(key_name)
print(f"Generated key for {key_name}: {key.hex()}")
print(f"Hash of {key_name}: {manager.hash_key(key_name)}")
manager.delete_key(key_name)
print(f"Key {key_name} deleted: {manager.get_key(key_name)}")