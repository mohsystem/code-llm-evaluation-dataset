#include <stdlib.h>

typedef struct {
    int *products;
    int size;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->products = (int*)malloc(sizeof(int));
    obj->products[0] = 1;
    obj->size = 1;
    return obj;
}

void add(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        free(obj->products);
        obj->products = (int*)malloc(sizeof(int));
        obj->products[0] = 1;
        obj->size = 1;
    } else {
        obj->products = (int*)realloc(obj->products, (obj->size + 1) * sizeof(int));
        obj->products[obj->size] = obj->products[obj->size - 1] * num;
        obj->size++;
    }
}

int getProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size) {
        return 0;
    } else {
        return obj->products[obj->size - 1] / obj->products[obj->size - k - 1];
    }
}