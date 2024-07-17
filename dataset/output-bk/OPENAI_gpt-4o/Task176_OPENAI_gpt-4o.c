#include <stdio.h>

#define MAX_SIZE 40000

typedef struct {
    int nums[MAX_SIZE];
    int prefixProducts[MAX_SIZE + 1];
    int size;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->size = 0;
    obj->prefixProducts[0] = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->size = 0;
        obj->prefixProducts[0] = 1;
    } else {
        obj->nums[obj->size] = num;
        obj->size++;
        obj->prefixProducts[obj->size] = obj->prefixProducts[obj->size - 1] * num;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size + 1) {
        return 0;
    }
    return obj->prefixProducts[obj->size] / obj->prefixProducts[obj->size - k];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

int main() {
    ProductOfNumbers* productOfNumbers = productOfNumbersCreate();
    productOfNumbersAdd(productOfNumbers, 3);
    productOfNumbersAdd(productOfNumbers, 0);
    productOfNumbersAdd(productOfNumbers, 2);
    productOfNumbersAdd(productOfNumbers, 5);
    productOfNumbersAdd(productOfNumbers, 4);
    printf("%d
", productOfNumbersGetProduct(productOfNumbers, 2));  // 20
    printf("%d
", productOfNumbersGetProduct(productOfNumbers, 3));  // 40
    printf("%d
", productOfNumbersGetProduct(productOfNumbers, 4));  // 0
    productOfNumbersAdd(productOfNumbers, 8);
    printf("%d
", productOfNumbersGetProduct(productOfNumbers, 2));  // 32

    productOfNumbersFree(productOfNumbers);
    return 0;
}