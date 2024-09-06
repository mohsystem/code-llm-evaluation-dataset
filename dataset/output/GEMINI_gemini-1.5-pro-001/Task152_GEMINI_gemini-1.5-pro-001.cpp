#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename K, typename V>
class HashTable {
private:
    int size;
    vector<list<pair<K, V>>> table;

    int _hash(const K& key) const {
        return hash<K>{}(key) % size;
    }

public:
    HashTable(int size) : size(size), table(size) {}

    void insert(const K& key, const V& value) {
        int index = _hash(key);
        table[index].push_back(make_pair(key, value));
    }

    bool deleteItem(const K& key) {
        int index = _hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    V* search(const K& key) {
        int index = _hash(key);
        for (const auto& entry : table[index]) {
            if (entry.first == key) {
                return const_cast<V*>(&(entry.second)); // Note: Potentially unsafe, modify with caution
            }
        }
        return nullptr;
    }

    friend ostream& operator<<(ostream& os, const HashTable<K, V>& ht) {
        for (int i = 0; i < ht.size; ++i) {
            os << "Index " << i << ": ";
            for (const auto& entry : ht.table[i]) {
                os << "(" << entry.first << ", " << entry.second << ") ";
            }
            os << endl;
        }
        return os;
    }
};