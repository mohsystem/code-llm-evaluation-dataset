
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    auto start = std::chrono::high_resolution_clock::now();
    int result = binarySearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::ofstream tempFile("execution_time.txt", std::ios::out | std::ios::trunc);
    if (tempFile.is_open()) {
        tempFile << "Execution time: " << duration.count() << " nanoseconds";
        tempFile.close();
        std::cout << "Execution time written to: execution_time.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    if (result != -1)
        std::cout << "Element found at index: " << result << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    return 0;
}
