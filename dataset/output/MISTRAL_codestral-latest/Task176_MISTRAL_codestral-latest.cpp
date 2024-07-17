#include <vector>

class ProductOfNumbers {
private:
    std::vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefixProducts = std::vector<int>(1, 1);
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        } else {
            return prefixProducts.back() / prefixProducts[prefixProducts.size() - k - 1];
        }
    }
};