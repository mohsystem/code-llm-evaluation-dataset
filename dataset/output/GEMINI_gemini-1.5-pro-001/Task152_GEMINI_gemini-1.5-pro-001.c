#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Entry {
    int key;
    int value;
    struct Entry* next;
};

struct HashTable {
    struct Entry** table;
};

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->table = (struct Entry**)malloc(sizeof(struct Entry*) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(struct HashTable* ht, int key, int value) {
    int index = hash(key);
    struct Entry* newEntry = (struct Entry*)malloc(sizeof(struct Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = ht->table[index];
    ht->table[index] = newEntry;
}

void deleteKey(struct HashTable* ht, int key) {
    int index = hash(key);
    struct Entry* current = ht->table[index];
    struct Entry* previous = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (previous == NULL) {
                ht->table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int search(struct HashTable* ht, int key) {
    int index = hash(key);
    struct Entry* current = ht->table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Not found
}

void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Entry* current = ht->table[i];
        while (current != NULL) {
            struct Entry* next = current->next;
            free(current);
            current = next;
        }
    }
    free(ht->table);
    free(ht);
}