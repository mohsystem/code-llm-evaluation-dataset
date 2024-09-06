#include <iostream>
#include <vector>

class HashTable {
private:
    const int SIZE = 10;
    std::vector<std::string> table;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashTable() : table(SIZE, "") {}

    void insert(int key, const std::string& value) {
        int hashKey = hashFunction(key);
        table[hashKey] = value;
    }

    void deleteKey(int key) {
        int hashKey = hashFunction(key);
        table[hashKey] = "";
    }

    std::string search(int key) {
        int hashKey = hashFunction(key);
        return table[hashKey];
    }
};

int main() {
    HashTable ht;
    ht.insert(1, "one");
    ht.insert(2, "two");
    ht.insert(11, "eleven");
    std::cout << "Search key 1: " << ht.search(1) << std::endl;
    std::cout << "Search key 2: " << ht.search(2) << std::endl;
    ht.deleteKey(1);
    std::cout << "Search key 1 after deletion: " << ht.search(1) << std::endl;
    return 0;
}