class HashTable:
    def __init__(self):
        self.size = 10
        self.table = [None]*self.size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        hash_key = self.hash_function(key)
        self.table[hash_key] = value

    def delete(self, key):
        hash_key = self.hash_function(key)
        self.table[hash_key] = None

    def search(self, key):
        hash_key = self.hash_function(key)
        return self.table[hash_key]

ht = HashTable()
ht.insert(1, 'one')
ht.insert(2, 'two')
ht.insert(11, 'eleven')
print(f"Search key 1: {ht.search(1)}")
print(f"Search key 2: {ht.search(2)}")
ht.delete(1)
print(f"Search key 1 after deletion: {ht.search(1)}")