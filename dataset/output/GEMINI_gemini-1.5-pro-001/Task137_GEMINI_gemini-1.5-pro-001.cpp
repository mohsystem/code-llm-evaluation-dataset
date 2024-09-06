#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, unordered_map<string, object>> products = {
    {"001", {{"name", "Apple"}, {"price", 1.00}, {"stock", 100}}},
    {"002", {{"name", "Banana"}, {"price", 0.50}, {"stock", 50}}},
    {"003", {{"name", "Orange"}, {"price", 1.20}, {"stock", 75}}}
};

string getProductDetails(const string& productId) {
    auto product = products.find(productId);
    if (product != products.end()) {
        return "Product Name: " + product->second["name"].get<string>() + "\nPrice: $" + to_string(product->second["price"].get<double>()) + "\nStock: " + to_string(product->second["stock"].get<int>());
    } else {
        return "Product not found.";
    }
}

int main() {
    string productId;

    while (true) {
        cout << "Enter product ID (or 'q' to quit): ";
        cin >> productId;
        if (productId == "q") {
            break;
        }
        cout << getProductDetails(productId) << endl;
    }

    return 0;
}