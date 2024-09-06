// C++

#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::map<std::string, std::string>> productTable = {
    {"P123", {{"name", "Product 1"}, {"price", "10.99"}, {"quantity", "100"}}},
    {"P456", {{"name", "Product 2"}, {"price", "20.99"}, {"quantity", "50"}}},
    // Add more products as needed
};

std::map<std::string, std::string> getProductDetails(const std::string& productId) {
    auto it = productTable.find(productId);
    if (it != productTable.end()) {
        return it->second;
    } else {
        return {};
    }
}

int main() {
    std::string productId;

    // Get user input
    std::cout << "Enter product ID: ";
    std::cin >> productId;

    // Get product details
    std::map<std::string, std::string> productDetails = getProductDetails(productId);

    // Print product details
    if (!productDetails.empty()) {
        std::cout << "Name: " << productDetails["name"] << std::endl;
        std::cout << "Price: " << productDetails["price"] << std::endl;
        std::cout << "Quantity: " << productDetails["quantity"] << std::endl;
    } else {
        std::cout << "Product not found" << std::endl;
    }

    return 0;
}