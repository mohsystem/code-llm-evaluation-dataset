#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    int size;
    int* slots;
    string* data;

public:
    HashTable(int size) {
        this->size = size;
        this->slots = new int[size];
        this->data = new string[size];
        for (int i = 0; i < size; i++) {
            slots[i] = 0;
        }
    }

    void put(int key, string value) {
        int hashValue = hashFunction(key, size);

        if (slots[hashValue] == 0) {
            slots[hashValue] = key;
            data[hashValue] = value;
        } else {
            if (slots[hashValue] == key) {
                data[hashValue] = value; // replace
            } else {
                int nextSlot = rehash(hashValue, size);
                while (slots[nextSlot] != 0 && slots[nextSlot] != key) {
                    nextSlot = rehash(nextSlot, size);
                }

                if (slots[nextSlot] == 0) {
                    slots[nextSlot] = key;
                    data[nextSlot] = value;
                } else {
                    data[nextSlot] = value; // replace
                }
            }
        }
    }

    int hashFunction(int key, int size) {
        return key % size;
    }

    int rehash(int oldHash, int size) {
        return (oldHash + 1) % size;
    }

    string get(int key) {
        int startSlot = hashFunction(key, size);

        string value = "";
        bool stop = false;
        bool found = false;
        int position = startSlot;
        while (slots[position] != 0 && !found && !stop) {
            if (slots[position] == key) {
                found = true;
                value = data[position];
            } else {
                position = rehash(position, size);
                if (position == startSlot) {
                    stop = true;
                }
            }
        }
        return value;
    }
};

int main() {
    HashTable h(11);
    h.put(54, "cat");
    h.put(26, "dog");
    h.put(93, "lion");
    h.put(17, "tiger");
    h.put(77, "bird");
    h.put(31, "cow");
    h.put(44, "goat");
    h.put(55, "pig");
    h.put(20, "chicken");

    for (int i = 0; i < 11; i++) {
        cout << h.slots[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 11; i++) {
        cout << h.data[i] << " ";
    }
    cout << endl;

    cout << h.get(20) << endl;

    cout << h.get(17) << endl;
    h.put(20, "duck");
    cout << h.get(20) << endl;
    cout << h.get(99) << endl;

    return 0;
}