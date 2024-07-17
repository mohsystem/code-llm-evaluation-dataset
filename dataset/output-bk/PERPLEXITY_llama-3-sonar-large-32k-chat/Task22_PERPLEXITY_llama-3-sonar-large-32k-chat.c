#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void** data;
    int size;
} List;

List* filterList(List* list) {
    List* newList = (List*)malloc(sizeof(List));
    newList->size = 0;
    newList->data = (void**)malloc(list->size * sizeof(void*));
    for (int i = 0; i < list->size; i++) {
        if (*(int*)list->data[i] >= 0) {
            newList->data[newList->size] = list->data[i];
            newList->size++;
        }
    }
    return newList;
}