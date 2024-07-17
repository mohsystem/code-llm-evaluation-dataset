// C++ code
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::map<std::string, double>> productTable;
    productTable["apple"] = {{"price", 1.00}, {"stock", 100.0}};
    productTable["banana"] = {{"price", 0.50}, {"stock", 200.0}};
    productTable["orange"] = {{"price", 1.50}, {"stock", 50.0}};

    std::string productName;
    std::cout << "Enter product name: ";
    std::cin >> productName;

    if (productTable.find(productName) != productTable.end()) {
        std::cout << "Product: " << productName << std::endl;
        std::cout << "Price: " << productTable[productName]["price"] << std::endl;
        std::cout << "Stock: " << productTable[productName]["stock"] << std::endl;
    } else {
        std::cout << "Product not found" << std::endl;
    }

    return 0;
}