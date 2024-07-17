
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* oddOrEven(int* arr, int size) {
    if (size == 0) {
        return "even";
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements:\
");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    char* result = oddOrEven(arr, n);
    printf("%s\
", result);
    
    free(arr);
    return 0;
}
