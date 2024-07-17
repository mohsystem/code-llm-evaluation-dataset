#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct HashTable {
    int size;
    Entry** table;
} HashTable;

HashTable* create_hash_table() {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = 10;
    ht->table = malloc(sizeof(Entry*) * ht->size);
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hash(HashTable* ht, int key) {
    return abs(key) % ht->size;
}

void insert(HashTable* ht, int key, int value) {
    int index = hash(ht, key);
    Entry* entry = ht->table[index];
    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    Entry* new_entry = malloc(sizeof(Entry));
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = ht->table[index];
    ht->table[index] = new_entry;
}

void delete_key(HashTable* ht, int key) {
    int index = hash(ht, key);
    Entry* entry = ht->table[index];
    Entry* prev = NULL;
    while (entry != NULL) {
        if (entry->key == key) {
            if (prev == NULL) {
                ht->table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

int search(HashTable* ht, int key) {
    int index = hash(ht, key);
    Entry* entry = ht->table[index];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}