
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <cstdio>

int binary_search(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
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
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    auto start_time = std::chrono::high_resolution_clock::now();
    int result = binary_search(arr, target);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    double execution_time = duration.count() / 1e6; // Convert to seconds

    char temp_filename[] = "execution_time_XXXXXX";
    int fd = mkstemp(temp_filename);
    if (fd != -1) {
        FILE* temp_file = fdopen(fd, "w");
        if (temp_file != nullptr) {
            fprintf(temp_file, "Execution time: %.6f seconds", execution_time);
            fclose(temp_file);
            std::cout << "Execution time written to: " << temp_filename << std::endl;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
