
#include <stdio.h>

struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int value : 5;
};

int main() {
    struct Flags flags = {0};
    flags.flag1 = 1;
    flags.flag2 = 0;
    flags.flag3 = 1;
    flags.value = 15;

    printf("Flag1: %d\
", flags.flag1);
    printf("Flag2: %d\
", flags.flag2);
    printf("Flag3: %d\
", flags.flag3);
    printf("Value: %d\
", flags.value);

    return 0;
}
