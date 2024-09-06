#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct HashTable {
    Entry** table;
} HashTable;

HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Entry**)calloc(SIZE, sizeof(Entry*));
    return ht;
}

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(HashTable* ht, int key, int value) {
    int hashIndex = hash(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = ht->table[hashIndex];
    ht->table[hashIndex] = newEntry;
}

void deleteKey(HashTable* ht, int key) {
    int hashIndex = hash(key);
    Entry* current = ht->table[hashIndex];
    Entry* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->table[hashIndex] = current->next;
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

int search(HashTable* ht, int key) {
    int hashIndex = hash(key);
    Entry* current = ht->table[hashIndex];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}