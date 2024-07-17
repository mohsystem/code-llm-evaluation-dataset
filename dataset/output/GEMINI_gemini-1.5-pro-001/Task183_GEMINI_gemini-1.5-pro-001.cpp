#include <iostream>
#include <string>

int largestProduct(const std::string& digits, int span) {
    if (span < 1 || span > digits.length()) {
        return -1;
    }
    int maxProduct = 0;
    for (int i = 0; i <= digits.length() - span; i++) {
        int product = 1;
        for (int j = i; j < i + span; j++) {
            product *= (digits[j] - '0');
        }
        maxProduct = std::max(maxProduct, product);
    }
    return maxProduct;
}

int main() {
    // Example usage:
    std::string digits = "63915";
    int span = 3;
    int result = largestProduct(digits, span);
    std::cout << "Largest product: " << result << std::endl;
    return 0;
}