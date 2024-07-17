#include <iostream>
#include <fstream>
#include <chrono>

int binarySearch(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    auto start = std::chrono::high_resolution_clock::now();
    int result = binarySearch(arr, target, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeElapsed = end - start;
    std::ofstream file("execution_time.txt");
    file << "Execution time: " << timeElapsed.count() << " milliseconds
";
    std::cout << "Element found at index " << result << std::endl;
    return 0;
}