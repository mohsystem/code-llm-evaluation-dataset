
#include <iostream>

struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int value : 5;
};

int main() {
    Flags flags = {0};
    flags.flag1 = 1;
    flags.flag2 = 0;
    flags.flag3 = 1;
    flags.value = 15;

    std::cout << "Flag1: " << flags.flag1 << std::endl;
    std::cout << "Flag2: " << flags.flag2 << std::endl;
    std::cout << "Flag3: " << flags.flag3 << std::endl;
    std::cout << "Value: " << flags.value << std::endl;

    return 0;
}
