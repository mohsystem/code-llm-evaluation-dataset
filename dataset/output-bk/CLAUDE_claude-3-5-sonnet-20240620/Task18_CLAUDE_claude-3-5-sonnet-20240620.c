
#include <stdio.h>

int convertBinaryArrayToInt(int* binary, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = result * 2 + binary[i];
    }
    return result;
}

int main() {
    int test1[] = {0, 0, 0, 1};
    int test2[] = {0, 0, 1, 0};
    int test3[] = {0, 1, 0, 1};
    int test4[] = {1, 0, 0, 1};
    int test5[] = {0, 1, 1, 0};
    int test6[] = {1, 1, 1, 1};
    int test7[] = {1, 0, 1, 1};

    printf("%d\
", convertBinaryArrayToInt(test1, 4)); // 1
    printf("%d\
", convertBinaryArrayToInt(test2, 4)); // 2
    printf("%d\
", convertBinaryArrayToInt(test3, 4)); // 5
    printf("%d\
", convertBinaryArrayToInt(test4, 4)); // 9
    printf("%d\
", convertBinaryArrayToInt(test5, 4)); // 6
    printf("%d\
", convertBinaryArrayToInt(test6, 4)); // 15
    printf("%d\
", convertBinaryArrayToInt(test7, 4)); // 11

    return 0;
}
