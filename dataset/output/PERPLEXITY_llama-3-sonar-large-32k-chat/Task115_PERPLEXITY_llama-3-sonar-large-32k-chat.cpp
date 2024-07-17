#include <iostream>

struct BitFields {
    unsigned int a:1;
    unsigned int b:2;
    unsigned int c:3;
};

int main() {
    BitFields bf;
    bf.a = 1;
    bf.b = 2;
    bf.c = 3;
    std::cout << "a: " << bf.a << std::endl;
    std::cout << "b: " << bf.b << std::endl;
    std::cout << "c: " << bf.c << std::endl;
    return 0;
}