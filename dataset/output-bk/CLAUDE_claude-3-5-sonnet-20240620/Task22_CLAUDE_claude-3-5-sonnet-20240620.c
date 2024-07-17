
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* filterList(void** list, int size, int* resultSize) {
    int* result = malloc(size * sizeof(int));
    *resultSize = 0;

    for (int i = 0; i < size; i++) {
        if (*(int*)(&list[i]) == (int)list[i]) {
            result[*resultSize] = *(int*)(&list[i]);
            (*resultSize)++;
        }
    }

    return result;
}

int main() {
    void* list1[] = {(void*)1, (void*)2, "a", "b"};
    void* list2[] = {(void*)1, "a", "b", (void*)0, (void*)15};
    void* list3[] = {(void*)1, (void*)2, "a", "b", "aasf", "1", "123", (void*)123};

    int resultSize;
    int* result;

    result = filterList(list1, 4, &resultSize);
    printf("Filtered list 1: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\
");
    free(result);

    result = filterList(list2, 5, &resultSize);
    printf("Filtered list 2: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\
");
    free(result);

    result = filterList(list3, 8, &resultSize);
    printf("Filtered list 3: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\
");
    free(result);

    return 0;
}
