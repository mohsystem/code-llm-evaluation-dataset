#include <iostream>
#include <vector>

class ProductOfNumbers {
private:
    std::vector<int> products;

public:
    ProductOfNumbers() {
        products.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            products = {1};
        } else {
            products.push_back(products.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= products.size()) {
            return 0;
        }
        return products.back() / products[products.size() - k - 1];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    std::cout << productOfNumbers.getProduct(2) << std::endl;  // return 20
    std::cout << productOfNumbers.getProduct(3) << std::endl;  // return 40
    std::cout << productOfNumbers.getProduct(4) << std::endl;  // return 0
    productOfNumbers.add(8);
    std::cout << productOfNumbers.getProduct(2) << std::endl;  // return 32
    return 0;
}