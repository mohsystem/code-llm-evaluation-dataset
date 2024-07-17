// C++

#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::map<std::string, int>> productTable = {
    {"product1", {{"price", 10}, {"quantity", 50}}},
    // Add more products as needed
};

std::string getProductDetails(const std::map<std::string, std::map<std::string, int>>& productTable, const std::string& productName) {
    auto it = productTable.find(productName);
    if (it != productTable.end()) {
        std::string details = "Price: " + std::to_string(it->second["price"]) + ", Quantity: " + std::to_string(it->second["quantity"]);
        return details;
    }
    return "Product not found";
}

int main() {
    std::string productName;
    std::cout << "Enter product name: ";
    std::getline(std::cin, productName);
    std::cout << getProductDetails(productTable, productName) << std::endl;
    return 0;
}