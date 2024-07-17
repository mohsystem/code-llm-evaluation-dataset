
#include <iostream>
#include <vector>
#include <sstream>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter integers separated by spaces: ";
    std::getline(std::cin, input);

    std::vector<int> arr;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
