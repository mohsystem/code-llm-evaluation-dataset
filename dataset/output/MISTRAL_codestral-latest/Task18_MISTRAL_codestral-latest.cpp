#include <iostream>
#include <vector>

int binaryArrayToNumber(std::vector<int> arr) {
    int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        result = result * 2 + arr[i];
    }
    return result;
}