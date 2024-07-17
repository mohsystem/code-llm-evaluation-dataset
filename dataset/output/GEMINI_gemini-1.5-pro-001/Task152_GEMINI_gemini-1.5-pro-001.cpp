#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    int size;
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key;
    }

public:
    HashTable(int size) : size(size), table(size) {}

    int getSize() const {
        return size;
    }

    bool containsKey(int key) {
        int index = hash(key) % size;
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return true;
            }
        }
        return false;
    }

    void insert(int key, int value) {
        int index = hash(key) % size;
        table[index].emplace_back(key, value);
    }

    void deleteKey(int key) {
        int index = hash(key) % size;
        table[index].remove_if([key](const auto& entry) {
            return entry.first == key;
        });
    }

    int search(int key) {
        int index = hash(key) % size;
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return entry.second;
            }
        }
        return -1; // Not found
    }
};