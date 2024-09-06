#include <stdio.h>

#define MAX_SIZE 40001

typedef struct {
    int products[MAX_SIZE];
    int size;
} ProductOfNumbers;

void ProductOfNumbersInit(ProductOfNumbers* obj) {
    obj->products[0] = 1;
    obj->size = 1;
}

void ProductOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->products[0] = 1;
        obj->size = 1;
    } else {
        obj->products[obj->size] = obj->products[obj->size - 1] * num;
        obj->size++;
    }
}

int ProductOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size) {
        return 0;
    }
    return obj->products[obj->size - 1] / obj->products[obj->size - k - 1];
}

int main() {
    ProductOfNumbers productOfNumbers;
    ProductOfNumbersInit(&productOfNumbers);
    
    ProductOfNumbersAdd(&productOfNumbers, 3);
    ProductOfNumbersAdd(&productOfNumbers, 0);
    ProductOfNumbersAdd(&productOfNumbers, 2);
    ProductOfNumbersAdd(&productOfNumbers, 5);
    ProductOfNumbersAdd(&productOfNumbers, 4);
    printf("%d\n", ProductOfNumbersGetProduct(&productOfNumbers, 2));  // return 20
    printf("%d\n", ProductOfNumbersGetProduct(&productOfNumbers, 3));  // return 40
    printf("%d\n", ProductOfNumbersGetProduct(&productOfNumbers, 4));  // return 0
    ProductOfNumbersAdd(&productOfNumbers, 8);
    printf("%d\n", ProductOfNumbersGetProduct(&productOfNumbers, 2));  // return 32

    return 0;
}