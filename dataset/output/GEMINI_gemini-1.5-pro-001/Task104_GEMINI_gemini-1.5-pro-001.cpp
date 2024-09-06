#include <iostream>
#include <string>

using namespace std;

const int BUFFER_SIZE = 1024;

int main() {
    char buffer[BUFFER_SIZE];

    cout << "Enter your input (max " << BUFFER_SIZE << " characters): ";
    cin.getline(buffer, BUFFER_SIZE);

    string inputData(buffer);

    cout << "\nYou entered:\n" << inputData << endl;

    return 0;
}