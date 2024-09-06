// C

#include <stdio.h>
#include <string.h>

// Assuming we have a simple structure to represent a product
typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

// Assuming we have a fixed size product table
#define MAX_PRODUCTS 10
Product productTable[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(const char* name, float price, int quantity) {
    if (numProducts < MAX_PRODUCTS) {
        strcpy(productTable[numProducts].name, name);
        productTable[numProducts].price = price;
        productTable[numProducts].quantity = quantity;
        numProducts++;
    }
}

Product* getProductDetails(const char* productId) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productId, productTable[i].name) == 0) {
            return &productTable[i];
        }
    }
    return NULL;
}

int main() {
    // Initialize product table
    addProduct("P123", 10.99, 100);
    addProduct("P456", 20.99, 50);
    // Add more products as needed

    char productId[50];

    // Get user input
    printf("Enter product ID: ");
    scanf("%s", productId);

    // Get product details
    Product* productDetails = getProductDetails(productId);

    // Print product details
    if (productDetails != NULL) {
        printf("Name: %s\n", productDetails->name);
        printf("Price: %.2f\n", productDetails->price);
        printf("Quantity: %d\n", productDetails->quantity);
    } else {
        printf("Product not found\n");
    }

    return 0;
}