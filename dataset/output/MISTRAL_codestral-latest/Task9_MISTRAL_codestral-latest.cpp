#include <vector>
#include <string>

std::string oddOrEven(const std::vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    return sum % 2 == 0 ? "even" : "odd";
}