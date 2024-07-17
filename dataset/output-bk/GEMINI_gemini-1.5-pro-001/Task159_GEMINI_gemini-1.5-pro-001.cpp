#include <iostream>

using namespace std;

int main() {
    int bufferSize;

    cout << "Enter the buffer size: ";
    cin >> bufferSize;

    if (cin.fail() || bufferSize <= 0) {
        cerr << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    int *buffer = new int[bufferSize];

    for (int i = 0; i < bufferSize; ++i) {
        cout << "Enter data for index " << i << ": ";
        cin >> buffer[i];

        if (cin.fail()) {
            cerr << "Invalid input. Please enter an integer." << endl;
            delete[] buffer;
            return 1;
        }
    }

    while (true) {
        int index;
        cout << "Enter an index to read (or -1 to exit): ";
        cin >> index;

        if (cin.fail()) {
            cerr << "Invalid input. Please enter an integer." << endl;
            continue;
        }

        if (index == -1) {
            break;
        }

        if (index >= 0 && index < bufferSize) {
            cout << "Data at index " << index << ": " << buffer[index] << endl;
        } else {
            cout << "Index out of range." << endl;
        }
    }

    delete[] buffer;

    return 0;
}