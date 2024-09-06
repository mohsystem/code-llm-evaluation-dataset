class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size

    def __str__(self):
        return str(self.table)

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = [(key, value)]
        else:
            self.table[index].append((key, value))

    def delete(self, key):
        index = self._hash(key)
        if self.table[index] is not None:
            original_size = len(self.table[index])
            self.table[index] = [(k, v) for k, v in self.table[index] if k != key]
            if len(self.table[index]) == original_size:
                return False
            return True
        return False

    def search(self, key):
        index = self._hash(key)
        if self.table[index] is not None:
            for k, v in self.table[index]:
                if k == key:
                    return v
        return None