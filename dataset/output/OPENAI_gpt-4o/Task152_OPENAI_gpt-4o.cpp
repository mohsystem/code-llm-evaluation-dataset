#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int size;
    list<pair<int, string>>* table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int size) {
        this->size = size;
        table = new list<pair<int, string>>[size];
    }

    void insert(int key, string value) {
        int hashKey = hashFunction(key);
        for (auto& pair : table[hashKey]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[hashKey].emplace_back(key, value);
    }

    void deleteKey(int key) {
        int hashKey = hashFunction(key);
        table[hashKey].remove_if([key](pair<int, string>& pair) {
            return pair.first == key;
        });
    }

    string search(int key) {
        int hashKey = hashFunction(key);
        for (auto& pair : table[hashKey]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "None";
    }
};

int main() {
    HashTable ht(10);
    ht.insert(1, "one");
    ht.insert(2, "two");
    cout << ht.search(1) << endl; // should print "one"
    ht.deleteKey(1);
    cout << ht.search(1) << endl; // should print "None"
    return 0;
}