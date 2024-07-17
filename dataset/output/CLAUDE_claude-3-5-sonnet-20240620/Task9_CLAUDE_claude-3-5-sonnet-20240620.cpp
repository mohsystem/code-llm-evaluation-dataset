
#include <iostream>
#include <vector>

std::string oddOrEven(const std::vector<int>& arr) {
    if (arr.empty()) {
        return "even";
    }
    
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    std::vector<int> arr(n);
    std::cout << "Enter the elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    std::cout << oddOrEven(arr) << std::endl;
    return 0;
}
