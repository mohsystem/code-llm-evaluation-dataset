
#include <stdio.h>

int persistence(long long num) {
    if (num < 10) {
        return 0;
    }
    
    long long product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    
    return 1 + persistence(product);
}

int main() {
    printf("%d\\n", persistence(39));  // Output: 3
    printf("%d\\n", persistence(999)); // Output: 4
    printf("%d\\n", persistence(4));   // Output: 0
    return 0;
}
