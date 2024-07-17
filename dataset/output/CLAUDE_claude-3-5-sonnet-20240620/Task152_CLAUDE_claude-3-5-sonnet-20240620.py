
class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        hash_index = self.hash_function(key)
        for item in self.table[hash_index]:
            if item[0] == key:
                item[1] = value
                return
        self.table[hash_index].append([key, value])

    def delete(self, key):
        hash_index = self.hash_function(key)
        for i, item in enumerate(self.table[hash_index]):
            if item[0] == key:
                del self.table[hash_index][i]
                return

    def search(self, key):
        hash_index = self.hash_function(key)
        for item in self.table[hash_index]:
            if item[0] == key:
                return item[1]
        return None

def main():
    ht = HashTable(10)
    ht.insert("apple", 5)
    ht.insert("banana", 7)
    ht.insert("orange", 3)

    print(ht.search("apple"))  # Output: 5
    print(ht.search("grape"))  # Output: None

    ht.delete("banana")
    print(ht.search("banana"))  # Output: None

if __name__ == "__main__":
    main()
