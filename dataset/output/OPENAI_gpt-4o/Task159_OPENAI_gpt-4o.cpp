// C++ code

#include <iostream>
using namespace std;

int main() {
    int size;
    
    cout << "Enter the size of the buffer: ";
    cin >> size;
    int* buffer = new int[size];

    while (true) {
        int idx;
        cout << "Enter index (-1 to quit): ";
        cin >> idx;
        if (idx == -1) break;

        if (idx >= 0 && idx < size) {
            cout << "Value at index " << idx << ": " << buffer[idx] << endl;
        } else {
            cout << "Index out of bounds." << endl;
        }
    }
    
    delete[] buffer;
    return 0;
}