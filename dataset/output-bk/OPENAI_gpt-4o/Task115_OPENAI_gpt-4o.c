#include <stdio.h>

struct BitFields {
    unsigned int field1 : 1;
    unsigned int field2 : 2;
    unsigned int field3 : 3;
};

int main() {
    struct BitFields bf = {1, 2, 5};
    printf("Field1: %u
", bf.field1);
    printf("Field2: %u
", bf.field2);
    printf("Field3: %u
", bf.field3);
    return 0;
}