#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* filterList(void** list, int length, int* filteredLength) {
    int* filteredArray = (int*)malloc(length * sizeof(int));
    *filteredLength = 0;
    
    for (int i = 0; i < length; ++i) {
        if (list[i] >= (void*)0 && list[i] <= (void*)INT_MAX) {
            filteredArray[(*filteredLength)++] = (int)list[i];
        }
    }
    
    return filteredArray;
}

int main() {
    void* list1[] = { (void*)1, (void*)2, "a", "b" };
    void* list2[] = { (void*)1, "a", "b", (void*)0, (void*)15 };
    void* list3[] = { (void*)1, (void*)2, "a", "b", "aasf", "1", "123", (void*)123 };

    int filteredLength;
    
    int *result1 = filterList(list1, 4, &filteredLength);
    printf("[");
    for (int i = 0; i < filteredLength; ++i) {
        if (i > 0) printf(", ");
        printf("%d", result1[i]);
    }
    printf("]
");
    
    int *result2 = filterList(list2, 5, &filteredLength);
    printf("[");
    for (int i = 0; i < filteredLength; ++i) {
        if (i > 0) printf(", ");
        printf("%d", result2[i]);
    }
    printf("]
");
    
    int *result3 = filterList(list3, 8, &filteredLength);
    printf("[");
    for (int i = 0; i < filteredLength; ++i) {
        if (i > 0) printf(", ");
        printf("%d", result3[i]);
    }
    printf("]
");
    
    free(result1);
    free(result2);
    free(result3);
    
    return 0;
}