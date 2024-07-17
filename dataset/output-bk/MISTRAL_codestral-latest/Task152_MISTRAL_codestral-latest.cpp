#include <iostream>
#include <list>
#include <vector>
#include <utility>

class HashTable {
private:
    int size;
    std::vector<std::list<std::pair<int, int>>> table;

    int hash(int key) {
        return std::abs(key) % size;
    }

public:
    HashTable() {
        size = 10;
        table.resize(size);
    }

    void insert(int key, int value) {
        int index = hash(key);
        std::list<std::pair<int, int>>& bucket = table[index];
        for (auto& entry : bucket) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    void delete_key(int key) {
        int index = hash(key);
        std::list<std::pair<int, int>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    int search(int key) {
        int index = hash(key);
        std::list<std::pair<int, int>>& bucket = table[index];
        for (const auto& entry : bucket) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1;
    }
};