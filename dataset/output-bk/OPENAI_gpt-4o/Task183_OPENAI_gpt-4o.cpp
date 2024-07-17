#include <iostream>
#include <string>

int largestProduct(const std::string& digits, int span) {
    if (span == 0) {
        return 1;
    }
    int maxProduct = 0;
    for (size_t i = 0; i <= digits.size() - span; i++) {
        int product = 1;
        for (size_t j = i; j < i + span; j++) {
            product *= digits[j] - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    std::string digits = "63915";
    int span = 3;
    std::cout << largestProduct(digits, span) << std::endl;
    return 0;
}