#include <stdio.h>

struct BitFields {
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 3;
};

void display(struct BitFields bf) {
    printf("a: %d, b: %d, c: %d\n", bf.a, bf.b, bf.c);
}

int main() {
    struct BitFields bitFields = {1, 2, 5};
    display(bitFields);
    return 0;
}