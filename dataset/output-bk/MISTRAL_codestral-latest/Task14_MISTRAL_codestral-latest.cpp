#include <iostream>
#include <vector>

int find_even_index(std::vector<int> arr) {
    int left_sum, right_sum;
    for (int i = 0; i < arr.size(); i++) {
        left_sum = 0;
        right_sum = 0;
        for (int j = 0; j < i; j++) {
            left_sum += arr[j];
        }
        for (int j = i + 1; j < arr.size(); j++) {
            right_sum += arr[j];
        }
        if (left_sum == right_sum) {
            return i;
        }
    }
    return -1;
}