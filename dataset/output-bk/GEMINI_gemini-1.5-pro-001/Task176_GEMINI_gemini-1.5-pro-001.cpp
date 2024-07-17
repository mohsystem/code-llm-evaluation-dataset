class ProductOfNumbers {
public:
    vector<int> prefixProducts;

    ProductOfNumbers() {
        prefixProducts.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefixProducts.clear();
            prefixProducts.push_back(1);
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefixProducts.size()) {
            return 0;
        }
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - k - 1];
    }
};