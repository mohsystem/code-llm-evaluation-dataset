
#include <iostream>
#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    int size;
    std::vector<std::list<std::pair<std::string, int>>> table;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int size) : size(size), table(size) {}

    void insert(const std::string& key, int value) {
        int hashIndex = hashFunction(key);
        for (auto& entry : table[hashIndex]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        table[hashIndex].emplace_back(key, value);
    }

    void remove(const std::string& key) {
        int hashIndex = hashFunction(key);
        table[hashIndex].remove_if([&key](const auto& entry) { return entry.first == key; });
    }

    int* search(const std::string& key) {
        int hashIndex = hashFunction(key);
        for (auto& entry : table[hashIndex]) {
            if (entry.first == key) {
                return &entry.second;
            }
        }
        return nullptr;
    }
};

int main() {
    HashTable ht(10);
    ht.insert("apple", 5);
    ht.insert("banana", 7);
    ht.insert("orange", 3);

    int* result = ht.search("apple");
    std::cout << (result ? *result : -1) << std::endl;  // Output: 5

    result = ht.search("grape");
    std::cout << (result ? *result : -1) << std::endl;  // Output: -1

    ht.remove("banana");
    result = ht.search("banana");
    std::cout << (result ? *result : -1) << std::endl;  // Output: -1

    return 0;
}
