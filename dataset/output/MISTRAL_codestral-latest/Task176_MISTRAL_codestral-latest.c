#include <stdlib.h>

typedef struct {
    int* prefixProducts;
    int size;
    int capacity;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->prefixProducts = (int*)malloc(sizeof(int));
    obj->prefixProducts[0] = 1;
    obj->size = 1;
    obj->capacity = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->prefixProducts[0] = 1;
        obj->size = 1;
    } else {
        if (obj->size == obj->capacity) {
            obj->capacity *= 2;
            obj->prefixProducts = (int*)realloc(obj->prefixProducts, obj->capacity * sizeof(int));
        }
        obj->prefixProducts[obj->size] = obj->prefixProducts[obj->size - 1] * num;
        obj->size++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size) {
        return 0;
    } else {
        return obj->prefixProducts[obj->size - 1] / obj->prefixProducts[obj->size - k - 1];
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->prefixProducts);
    free(obj);
}