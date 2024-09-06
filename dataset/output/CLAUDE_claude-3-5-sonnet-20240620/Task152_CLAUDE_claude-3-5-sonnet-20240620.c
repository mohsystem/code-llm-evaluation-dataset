
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_NAME 256

typedef struct Entry {
    char key[MAX_NAME];
    int value;
    struct Entry* next;
} Entry;

typedef struct {
    Entry* table[SIZE];
} HashTable;

unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % SIZE;
}

HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    for (int i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert(HashTable* ht, const char* key, int value) {
    unsigned int index = hash(key);
    Entry* newEntry = malloc(sizeof(Entry));
    strncpy(newEntry->key, key, MAX_NAME - 1);
    newEntry->key[MAX_NAME - 1] = '\\0';
    newEntry->value = value;
    newEntry->next = ht->table[index];
    ht->table[index] = newEntry;
}

void delete(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    Entry* current = ht->table[index];
    Entry* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int search(HashTable* ht, const char* key) {
    unsigned int index = hash(key);
    Entry* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        Entry* current = ht->table[i];
        while (current != NULL) {
            Entry* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

int main() {
    HashTable* ht = createHashTable();

    insert(ht, "apple", 5);
    insert(ht, "banana", 7);
    insert(ht, "orange", 3);

    printf("%d\\n", search(ht, "banana")); // Output: 7

    delete(ht, "banana");
    printf("%d\\n", search(ht, "banana")); // Output: -1 (Not found)

    freeHashTable(ht);
    return 0;
}
