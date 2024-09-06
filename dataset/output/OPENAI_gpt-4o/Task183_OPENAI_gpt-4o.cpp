#include <iostream>
#include <string>

int findLargestProduct(const std::string& sequence, int span) {
    int maxProduct = 0;
    int length = sequence.length();
    
    for (int i = 0; i <= length - span; i++) {
        int product = 1;
        for (int j = 0; j < span; j++) {
            product *= sequence[i + j] - '0';
        }
        if (product > maxProduct) {
            maxProduct = product;
        }
    }
    return maxProduct;
}

int main() {
    std::string sequence = "63915";
    int span = 3;
    std::cout << findLargestProduct(sequence, span) << std::endl;
    return 0;
}