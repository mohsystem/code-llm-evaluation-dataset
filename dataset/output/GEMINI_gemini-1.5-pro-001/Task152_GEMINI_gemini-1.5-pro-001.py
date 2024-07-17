class HashTable:
    def __init__(self, size=10):
        self.table = [None] * size
        self.size = size

    def __len__(self):
        return len(self.table)

    def __contains__(self, key):
        index = self._hash(key) % self.size
        if self.table[index] is not None:
            for k, _ in self.table[index]:
                if k == key:
                    return True
        return False

    def insert(self, key, value):
        index = self._hash(key) % self.size
        if self.table[index] is None:
            self.table[index] = [(key, value)]
        else:
            self.table[index].append((key, value))

    def delete(self, key):
        index = self._hash(key) % self.size
        if self.table[index] is not None:
            original_size = len(self.table[index])
            self.table[index] = [(k, v) for k, v in self.table[index] if k != key]
            if len(self.table[index]) < original_size:
                return True
        return False

    def search(self, key):
        index = self._hash(key) % self.size
        if self.table[index] is not None:
            for k, v in self.table[index]:
                if k == key:
                    return v
        return None

    def _hash(self, key):
        return hash(key)