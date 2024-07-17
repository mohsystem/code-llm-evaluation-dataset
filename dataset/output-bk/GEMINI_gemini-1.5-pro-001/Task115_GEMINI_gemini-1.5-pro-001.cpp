#include <iostream>

struct Data {
    uint8_t field1 : 3;
    uint8_t field2 : 5;
};

int main() {
    Data data;
    data.field1 = 2;
    data.field2 = 20;

    std::cout << "field1: " << (int)data.field1 << std::endl;
    std::cout << "field2: " << (int)data.field2 << std::endl;

    return 0;
}