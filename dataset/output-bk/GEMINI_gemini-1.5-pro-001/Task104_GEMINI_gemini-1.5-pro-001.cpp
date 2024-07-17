#include <iostream>
#include <string>

using namespace std;

int main() {
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];

    cout << "Enter input: ";
    cin.getline(buffer, BUFFER_SIZE);

    cout << "Buffer contents: " << buffer << endl;
    return 0;
}