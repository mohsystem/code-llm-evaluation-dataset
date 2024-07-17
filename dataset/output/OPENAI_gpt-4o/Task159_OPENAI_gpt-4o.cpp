#include <iostream>
using namespace std;

int main() {
    int size = 10;
    char* buffer = new char[size];

    // Fill the buffer with some data
    for (int i = 0; i < size; i++) {
        buffer[i] = 'A' + i;
    }

    int index;
    // Allow the user to read data from the buffer
    while (true) {
        cout << "Enter index to read (0-" << (size-1) << ") or -1 to exit: ";
        cin >> index;

        if (index == -1) {
            break;
        }

        if (index >= 0 && index < size) {
            cout << "Data at index " << index << ": " << buffer[index] << endl;
        } else {
            cout << "Index out of bounds" << endl;
        }
    }

    delete[] buffer;
    return 0;
}