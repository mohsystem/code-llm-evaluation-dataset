#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    int key;
    char value[256];
} HashEntry;

HashEntry* table[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, const char* value) {
    int hashKey = hashFunction(key);
    table[hashKey] = malloc(sizeof(HashEntry));
    table[hashKey]->key = key;
    strcpy(table[hashKey]->value, value);
}

void deleteKey(int key) {
    int hashKey = hashFunction(key);
    if (table[hashKey] != NULL) {
        free(table[hashKey]);
        table[hashKey] = NULL;
    }
}

const char* search(int key) {
    int hashKey = hashFunction(key);
    if (table[hashKey] != NULL) {
        return table[hashKey]->value;
    }
    return NULL;
}

int main() {
    insert(1, "one");
    insert(2, "two");
    insert(11, "eleven");
    printf("Search key 1: %s\n", search(1));
    printf("Search key 2: %s\n", search(2));
    deleteKey(1);
    printf("Search key 1 after deletion: %s\n", search(1));
    return 0;
}