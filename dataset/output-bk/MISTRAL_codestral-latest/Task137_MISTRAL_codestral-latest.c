// C

#include <stdio.h>
#include <string.h>

// Assuming we have a struct to represent a product
typedef struct {
    int price;
    int quantity;
} Product;

// And a simple array to represent our product table
Product productTable[] = {
    {10, 50},  // product1
    // Add more products as needed
};

void getProductDetails(Product* productTable, char* productName) {
    if (strcmp(productName, "product1") == 0) {
        printf("Price: %d, Quantity: %d
", productTable[0].price, productTable[0].quantity);
    } else {
        printf("Product not found
");
    }
}

int main() {
    char productName[50];
    printf("Enter product name: ");
    fgets(productName, sizeof(productName), stdin);
    // Remove newline character from fgets
    productName[strcspn(productName, "
")] = 0;
    getProductDetails(productTable, productName);
    return 0;
}