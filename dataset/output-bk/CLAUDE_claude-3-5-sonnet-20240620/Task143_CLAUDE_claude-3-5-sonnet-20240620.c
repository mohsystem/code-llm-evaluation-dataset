
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char input[MAX_SIZE];
    int arr[MAX_SIZE];
    int n = 0;

    printf("Enter integers separated by spaces: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \
");
    while (token != NULL && n < MAX_SIZE) {
        arr[n++] = atoi(token);
        token = strtok(NULL, " \
");
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\
");

    return 0;
}
