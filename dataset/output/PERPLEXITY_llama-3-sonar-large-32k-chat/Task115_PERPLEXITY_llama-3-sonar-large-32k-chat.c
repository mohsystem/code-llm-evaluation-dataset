#include <stdio.h>

struct BitFields {
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 3;
};

int main() {
    struct BitFields bf;
    bf.a = 1;
    bf.b = 2;
    bf.c = 3;
    printf("%d %d %d\n", bf.a, bf.b, bf.c);
    return 0;
}