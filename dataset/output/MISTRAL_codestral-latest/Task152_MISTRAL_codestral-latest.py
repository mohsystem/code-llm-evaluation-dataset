class HashTable:
    def __init__(self):
        self.size = 10000
        self.table = [None] * self.size

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        hash_index = self._hash(key)
        if self.table[hash_index] is None:
            self.table[hash_index] = []
        self.table[hash_index].append((key, value))

    def delete(self, key):
        hash_index = self._hash(key)
        if self.table[hash_index] is not None:
            for i, (k, v) in enumerate(self.table[hash_index]):
                if k == key:
                    del self.table[hash_index][i]
                    return

    def search(self, key):
        hash_index = self._hash(key)
        if self.table[hash_index] is not None:
            for k, v in self.table[hash_index]:
                if k == key:
                    return v
        return None