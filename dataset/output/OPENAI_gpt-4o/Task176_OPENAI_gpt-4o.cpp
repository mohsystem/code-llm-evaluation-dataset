#include <vector>
#include <iostream>

class ProductOfNumbers {
private:
    std::vector<int> nums;
    std::vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            nums.clear();
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } else {
            nums.push_back(num);
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        }
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - 1 - k];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    std::cout << productOfNumbers.getProduct(2) << std::endl;  // 20
    std::cout << productOfNumbers.getProduct(3) << std::endl;  // 40
    std::cout << productOfNumbers.getProduct(4) << std::endl;  // 0
    productOfNumbers.add(8);
    std::cout << productOfNumbers.getProduct(2) << std::endl;  // 32
}