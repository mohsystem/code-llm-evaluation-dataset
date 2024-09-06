
typedef struct {
    int* products;
    int size;
    int capacity;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->capacity = 40000;
    obj->products = (int*)malloc(sizeof(int) * obj->capacity);
    obj->size = 1;
    obj->products[0] = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->size = 1;
        obj->products[0] = 1;
    } else {
        if (obj->size == obj->capacity) {
            obj->capacity *= 2;
            obj->products = (int*)realloc(obj->products, sizeof(int) * obj->capacity);
        }
        obj->products[obj->size] = obj->products[obj->size - 1] * num;
        obj->size++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size) {
        return 0;
    }
    return obj->products[obj->size - 1] / obj->products[obj->size - k - 1];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->products);
    free(obj);
}
