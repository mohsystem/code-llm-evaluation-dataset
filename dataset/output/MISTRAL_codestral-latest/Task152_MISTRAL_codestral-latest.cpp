#include <iostream>
#include <list>
#include <vector>
#include <utility>

class HashTable {
private:
    static const int SIZE = 10000;
    std::vector<std::list<std::pair<int, int>>> table;

    int hash(int key) {
        return std::abs(key) % SIZE;
    }

public:
    HashTable() : table(SIZE) {}

    void insert(int key, int value) {
        int hashIndex = hash(key);
        table[hashIndex].emplace_back(key, value);
    }

    void deleteKey(int key) {
        int hashIndex = hash(key);
        auto& bucket = table[hashIndex];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                break;
            }
        }
    }

    int search(int key) {
        int hashIndex = hash(key);
        auto& bucket = table[hashIndex];
        for (const auto& entry : bucket) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1;
    }
};