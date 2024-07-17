#include <iostream>
#include <vector>

int findOdd(std::vector<int> arr) {
    for (int num : arr) {
        int count = 0;
        for (int i : arr) {
            if (i == num) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return num;
        }
    }
    return -1;
}