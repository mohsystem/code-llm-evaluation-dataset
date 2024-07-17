class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        hash_key = self.hash_function(key)
        if self.table[hash_key] is None:
            self.table[hash_key] = [(key, value)]
        else:
            for pair in self.table[hash_key]:
                if pair[0] == key:
                    pair = (key, value)
                    return
            self.table[hash_key].append((key, value))

    def delete(self, key):
        hash_key = self.hash_function(key)
        if self.table[hash_key] is not None:
            self.table[hash_key] = [pair for pair in self.table[hash_key] if pair[0] != key]

    def search(self, key):
        hash_key = self.hash_function(key)
        if self.table[hash_key] is not None:
            for pair in self.table[hash_key]:
                if pair[0] == key:
                    return pair[1]
        return None

# Example usage:
ht = HashTable(10)
ht.insert(1, 'one')
ht.insert(2, 'two')
print(ht.search(1)) # should print 'one'
ht.delete(1)
print(ht.search(1)) # should print 'None'