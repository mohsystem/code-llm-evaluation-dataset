#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>

int binarySearch(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[10000];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    for (int i = 0; i < 10000; i++) {
        arr[i] = dis(gen);
    }
    std::sort(arr, arr + 10000);

    auto start_time = std::chrono::high_resolution_clock::now();
    int index = binarySearch(arr, 50, 0, 9999);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::ofstream file("temp.txt");
    file << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds\n";
    if (index != -1) {
        file << "Target found at index " << index << "\n";
    } else {
        file << "Target not found\n";
    }
    return 0;
}