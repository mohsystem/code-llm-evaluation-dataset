#include <vector>

int find_even_index(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int leftSum = 0;
        int rightSum = 0;
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        for (int j = i + 1; j < arr.size(); j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}