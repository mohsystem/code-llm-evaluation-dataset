#include <iostream>
#include <vector>

int findMissing(std::vector<int>& arr) {
    int n = arr.size() + 1;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    return total - sum;
}