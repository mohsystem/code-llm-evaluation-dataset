#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString); 

    // Process the string (example: convert to uppercase)
    transform(inputString.begin(), inputString.end(), inputString.begin(), ::toupper); 

    cout << "Processed string: " << inputString << endl;

    return 0;
}