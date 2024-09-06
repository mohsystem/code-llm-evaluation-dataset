// C++ code
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::map<std::string, int>> productTable;
    productTable["apple"] = {{"price", 10}, {"stock", 100}};
    productTable["banana"] = {{"price", 5}, {"stock", 200}};
    productTable["orange"] = {{"price", 15}, {"stock", 50}};

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