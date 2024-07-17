#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **array;
    int size;
} List;

List filterList(List list) {
    List result;
    result.array = malloc(list.size * sizeof(void*));
    result.size = 0;

    for (int i = 0; i < list.size; i++) {
        if (list.array[i] != NULL) {
            result.array[result.size++] = list.array[i];
        }
    }

    return result;
}