class ProductOfNumbers {
public:
    vector<int> products;

    ProductOfNumbers() {
        products.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            products = vector<int>(1, 1);
        } else {
            products.push_back(products.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= products.size()) {
            return 0;
        } else {
            return products.back() / products[products.size() - k - 1];
        }
    }
};