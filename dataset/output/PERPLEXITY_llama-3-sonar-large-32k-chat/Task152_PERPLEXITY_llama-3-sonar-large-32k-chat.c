// C does not support classes or templates, so we have to use structures and functions
#include <stdio.h>
#include <string.h>

#define SIZE 11

typedef struct {
    int key;
    char* value;
} HashEntry;

HashEntry* table[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

int rehash(int oldHash) {
    return (oldHash + 1) % SIZE;
}

void put(int key, char* value) {
    int hashValue = hashFunction(key);

    if (table[hashValue] == NULL) {
        table[hashValue] = (HashEntry*)malloc(sizeof(HashEntry));
        table[hashValue]->key = key;
        table[hashValue]->value = (char*)malloc(strlen(value) + 1);
        strcpy(table[hashValue]->value, value);
    } else {
        if (table[hashValue]->key == key) {
            free(table[hashValue]->value);
            table[hashValue]->value = (char*)malloc(strlen(value) + 1);
            strcpy(table[hashValue]->value, value); // replace
        } else {
            int nextSlot = rehash(hashValue);
            while (table[nextSlot] != NULL && table[nextSlot]->key != key) {
                nextSlot = rehash(nextSlot);
            }

            if (table[nextSlot] == NULL) {
                table[nextSlot] = (HashEntry*)malloc(sizeof(HashEntry));
                table[nextSlot]->key = key;
                table[nextSlot]->value = (char*)malloc(strlen(value) + 1);
                strcpy(table[nextSlot]->value, value);
            } else {
                free(table[nextSlot]->value);
                table[nextSlot]->value = (char*)malloc(strlen(value) + 1);
                strcpy(table[nextSlot]->value, value); // replace
            }
        }
    }
}

char* get(int key) {
    int startSlot = hashFunction(key);

    char* value = NULL;
    int position = startSlot;
    while (table[position] != NULL) {
        if (table[position]->key == key) {
            value = table[position]->value;
            break;
        } else {
            position = rehash(position);
            if (position == startSlot) {
                break;
            }
        }
    }
    return value;
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }

    put(54, "cat");
    put(26, "dog");
    put(93, "lion");
    put(17, "tiger");
    put(77, "bird");
    put(31, "cow");
    put(44, "goat");
    put(55, "pig");
    put(20, "chicken");

    for (int i = 0; i < SIZE; i++) {
        if (table[i] != NULL) {
            printf("%d: %s\n", table[i]->key, table[i]->value);
        }
    }

    printf("%s\n", get(20));

    printf("%s\n", get(17));
    put(20, "duck");
    printf("%s\n", get(20));
    printf("%s\n", get(99));

    return 0;
}