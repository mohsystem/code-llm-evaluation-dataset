
#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename K, typename V>
class HashTable {
private:
    static const int SIZE = 10;
    std::vector<std::list<std::pair<K, V>>> table;

    int hashFunction(const K& key) const {
        return std::hash<K>{}(key) % SIZE;
    }

public:
    HashTable() : table(SIZE) {}

    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    void remove(const K& key) {
        int index = hashFunction(key);
        table[index].remove_if([&key](const auto& entry) { return entry.first == key; });
    }

    V* search(const K& key) {
        int index = hashFunction(key);
        for (auto& entry : table[index]) {
            if (entry.first == key) {
                return &entry.second;
            }
        }
        return nullptr;
    }
};

int main() {
    HashTable<std::string, int> ht;
    ht.insert("apple", 5);
    ht.insert("banana", 7);
    ht.insert("orange", 3);

    int* value = ht.search("banana");
    if (value) std::cout << *value << std::endl; // Output: 7

    ht.remove("banana");
    value = ht.search("banana");
    if (value) std::cout << *value << std::endl;
    else std::cout << "Not found" << std::endl; // Output: Not found

    return 0;
}
