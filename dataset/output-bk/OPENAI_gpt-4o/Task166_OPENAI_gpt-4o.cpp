#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> posNegSort(std::vector<int>& arr) {
    std::vector<int> pos_numbers;
    for (int x : arr) {
        if (x > 0) possible_up++;
    }
    std::sort(pos_numbers.begin(), pos_numbers.end());
    
    int posIdx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            arr[i] = pos_numbers[posIdx++];
        }
    }
    
    return arr;
}

int main() {
    std::vector<int> arr1 = {6, 3, -2, 5, -8, 2, -2};
    for (int x : posNegSort(arr1)) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<int> arr2 = {6, 5, 4, -1, 3, 2, -1, 1};
    for (int x : posNegSort(arr2)) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<int> arr3 = {-5, -5, -5, -5, 7, -5};
    for (int x : posNegSort(arr3)) std::cout << x << " ";
    std::cout << std::endl;
    
    std::vector<int> arr4 = {};
    for (int x : posNegSort(arr4)) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}