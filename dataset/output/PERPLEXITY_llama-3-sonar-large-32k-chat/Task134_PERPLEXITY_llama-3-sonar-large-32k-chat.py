code here:
import hashlib

class KeyManager:
    def __init__(self):
        self.keys = {}

    def generate_key(self, username):
        key = hashlib.sha256(username.encode()).hexdigest()
        self.keys[username] = key
        return key

    def get_key(self, username):
        return self.keys.get(username)

    def delete_key(self, username):
        if username in self.keys:
            del self.keys[username]

manager = KeyManager()
print(manager.generate_key("user1"))
print(manager.get_key("user1"))
manager.delete_key("user1")
print(manager.get_key("user1"))