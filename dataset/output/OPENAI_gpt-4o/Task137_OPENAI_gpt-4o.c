#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int price;
} Product;

Product* create_product() {
    Product* product = (Product*)malloc(sizeof(Product));
    product->price = 0;
    return product;
}

void set_name(Product* product, const char* name) {
    strncpy(product->name, name, sizeof(product->name));
}

void set_price(Product* product, int price) {
    product->price = price;
}

char* get_name(Product* product) {
    return product->name;
}

int get_price(Product* product) {
    return product->price;
}