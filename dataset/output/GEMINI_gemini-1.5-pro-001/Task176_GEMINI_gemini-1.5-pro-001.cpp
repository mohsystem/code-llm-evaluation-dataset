class ProductOfNumbers {
public:
    vector<int> prefixProducts;

    ProductOfNumbers() {
        prefixProducts.push_back(1); // Initialize with 1 for empty subarrays
    }

    void add(int num) {
        if (num == 0) {
            prefixProducts.clear(); // Reset prefix products when encountering 0
            prefixProducts.push_back(1);
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProducts.size();
        if (k >= n) {
            return 0; // Not enough elements for the product
        }
        return prefixProducts.back() / prefixProducts[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */