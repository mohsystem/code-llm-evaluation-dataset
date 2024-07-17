// C code
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    double price;
    double stock;
} Product;

Product productTable[] = {
    {"apple", 1.00, 100.0},
    {"banana", 0.50, 200.0},
    {"orange", 1.50, 50.0}
};

int main() {
    char productName[20];
    printf("Enter product name: ");
    scanf("%s", productName);

    int i;
    for (i = 0; i < 3; i++) {
        if (strcmp(productTable[i].name, productName) == 0) {
            printf("Product: %s
", productTable[i].name);
            printf("Price: %f
", productTable[i].price);
            printf("Stock: %f
", productTable[i].stock);
            break;
        }
    }
    if (i == 3) {
        printf("Product not found
");
    }

    return 0;
}