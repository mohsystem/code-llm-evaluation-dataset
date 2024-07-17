#include <iostream>
#include <vector>

std::string oddOrEven(std::vector<int> array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    std::vector<int> array = {0, -1, -5};
    std::cout << oddOrEven(array) << std::endl;
    return 0;
}