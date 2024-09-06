#include <iostream>
#include <vector>

std::string oddOrEven(std::vector<int> arr) {
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    std::vector<int> arr1 = {0};
    std::vector<int> arr2 = {0, 1, 4};
    std::vector<int> arr3 = {0, -1, -5};

    std::cout << oddOrEven(arr1) << std::endl;  // Output: "even"
    std::cout << oddOrEven(arr2) << std::endl;  // Output: "odd"
    std::cout << oddOrEven(arr3) << std::endl;  // Output: "even"

    return 0;
}