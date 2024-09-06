#include <string>

class Product {
    std::string name;
    int price;

public:
    Product(): price(0) {}
    void setName(std::string name) {
        this->name = name;
    }
    void setPrice(int price) {
        this->price = price;
    }
    std::string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
};

extern "C" {
    Product* create_product() {
        return new Product();
    }
    void setName(Product* product, const char* name) {
        product->setName(name);
    }
    void setPrice(Product* product, int price) {
        product->setPrice(price);
    }
    const char* getName(Product* product) {
        return product->getName().c_str();
    }
    int getPrice(Product* product) {
        return product->getPrice();
    }
}