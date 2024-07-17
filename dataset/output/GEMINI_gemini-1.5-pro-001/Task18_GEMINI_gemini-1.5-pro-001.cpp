#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int binaryArrayToInteger(const vector<int>& binaryArray) {
    int decimalValue = 0;
    int arrayLength = binaryArray.size();
    for (int i = 0; i < arrayLength; i++) {
        if (binaryArray[i] == 1) {
            decimalValue += pow(2, arrayLength - 1 - i);
        }
    }
    return decimalValue;
}

int main() {
    vector<int> binaryArray1 = {0, 0, 0, 1};
    vector<int> binaryArray2 = {0, 0, 1, 0};
    vector<int> binaryArray3 = {0, 1, 0, 1};
    vector<int> binaryArray4 = {1, 0, 0, 1};
    vector<int> binaryArray5 = {0, 0, 1, 0};
    vector<int> binaryArray6 = {0, 1, 1, 0};
    vector<int> binaryArray7 = {1, 1, 1, 1};
    vector<int> binaryArray8 = {1, 0, 1, 1};

    cout << binaryArrayToInteger(binaryArray1) << endl; // Output: 1
    cout << binaryArrayToInteger(binaryArray2) << endl; // Output: 2
    cout << binaryArrayToInteger(binaryArray3) << endl; // Output: 5
    cout << binaryArrayToInteger(binaryArray4) << endl; // Output: 9
    cout << binaryArrayToInteger(binaryArray5) << endl; // Output: 2
    cout << binaryArrayToInteger(binaryArray6) << endl; // Output: 6
    cout << binaryArrayToInteger(binaryArray7) << endl; // Output: 15
    cout << binaryArrayToInteger(binaryArray8) << endl; // Output: 11

    return 0;
}