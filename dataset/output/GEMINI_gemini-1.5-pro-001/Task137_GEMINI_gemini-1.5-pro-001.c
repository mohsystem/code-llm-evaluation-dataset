#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    double price;
    int stock;
};

struct Product products[100] = {
    {"Apple", 1.00, 100},
    {"Banana", 0.50, 50},
    {"Orange", 1.20, 75},
};

int product_count = 3;

char* get_product_details(char* product_id) {
    for (int i = 0; i < product_count; i++) {
        if (strcmp(products[i].name, product_id) == 0) {
            static char details[100]; 
            sprintf(details, "Product Name: %s\nPrice: $%.2f\nStock: %d", products[i].name, products[i].price, products[i].stock);
            return details;
        }
    }
    return "Product not found.";
}

int main() {
    char product_id[50];
    while (1) {
        printf("Enter product ID (or 'q' to quit): ");
        scanf("%s", product_id);
        if (strcmp(product_id, "q") == 0) {
            break;
        }
        printf("%s\n", get_product_details(product_id));
    }
    return 0;
}