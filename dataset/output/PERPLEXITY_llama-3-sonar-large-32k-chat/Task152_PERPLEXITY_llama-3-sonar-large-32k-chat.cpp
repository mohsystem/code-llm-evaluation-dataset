#include <iostream>
#include <list>

class HashTable {
private:
    int size;
    std::list<std::pair<int, std::string>>* table;

public:
    HashTable(int size) {
        this->size = size;
        table = new std::list<std::pair<int, std::string>>[size];
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key, std::string value) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        table[index].push_back(std::make_pair(key, value));
    }

    void delete(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    std::string search(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return "";
    }
};

int main() {
    HashTable ht(10);
    ht.insert(1, "one");
    ht.insert(11, "eleven");
    ht.insert(21, "twenty one");
    std::cout << ht.search(1) << std::endl;  // Output: one
    std::cout << ht.search(11) << std::endl;  // Output: eleven
    std::cout << ht.search(21) << std::endl;  // Output: twenty one
    ht.delete(11);
    std::cout << ht.search(11) << std::endl;  // Output: 
    return 0;
}