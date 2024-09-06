// C code (Note: C does not have built-in support for maps or dictionaries, so we'll use a simple array of structs)
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int price;
    int stock;
} Product;

Product productTable[] = {
    {"apple", 10, 100},
    {"banana", 5, 200},
    {"orange", 15, 50}
};

int main() {
    char productName[20];
    printf("Enter product name: ");
    scanf("%s", productName);

    int i;
    for (i = 0; i < sizeof(productTable) / sizeof(Product); i++) {
        if (strcmp(productTable[i].name, productName) == 0) {
            printf("Product: %s\n", productName);
            printf("Price: %d\n", productTable[i].price);
            printf("Stock: %d\n", productTable[i].stock);
            return 0;
        }
    }

    printf("Product not found\n");
    return 0;
}