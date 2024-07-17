#include <stdio.h>
#include <stdint.h>

struct Data {
    uint8_t field1 : 3;
    uint8_t field2 : 5;
};

int main() {
    struct Data data;
    data.field1 = 2;
    data.field2 = 20;

    printf("field1: %u
", data.field1);
    printf("field2: %u
", data.field2);

    return 0;
}