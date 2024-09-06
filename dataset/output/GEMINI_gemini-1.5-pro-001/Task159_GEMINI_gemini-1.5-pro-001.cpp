#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the size of the buffer: ";
    cin >> size;

    if (cin.fail() || size <= 0) {
        cerr << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    string* buffer = new string[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter data for index " << i << ": ";
        cin >> buffer[i];
    }

    while (true) {
        int index;
        cout << "Enter an index to read data (or -1 to exit): ";
        cin >> index;

        if (cin.fail()) {
            cerr << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (index == -1) {
            break;
        } else if (index >= 0 && index < size) {
            cout << "Data at index " << index << ": " << buffer[index] << endl;
        } else {
            cout << "Index out of range." << endl;
        }
    }

    delete[] buffer;
    return 0;
}