#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    Entry **table;
    int size;
} HashTable;

HashTable *createHashTable(int size) {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL) {
        return NULL;
    }
    ht->size = size;
    ht->table = (Entry **)calloc(size, sizeof(Entry *));
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }
    return ht;
}

unsigned int hash(const char *key) {
    unsigned int hashVal = 0;
    while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal;
}

void insert(HashTable *ht, const char *key, const char *value) {
    unsigned int index = hash(key) % ht->size;
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    if (newEntry == NULL) {
        return;
    }
    newEntry->key = strdup(key);
    newEntry->value = strdup(value);
    newEntry->next = ht->table[index];
    ht->table[index] = newEntry;
}

char *search(HashTable *ht, const char *key) {
    unsigned int index = hash(key) % ht->size;
    Entry *entry = ht->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

void deleteItem(HashTable *ht, const char *key) {
    unsigned int index = hash(key) % ht->size;
    Entry *prev = NULL;
    Entry *entry = ht->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry->value);
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

void freeHashTable(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        Entry *entry = ht->table[i];
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// Example usage:
int main() {
    HashTable *ht = createHashTable(TABLE_SIZE);

    insert(ht, "apple", "red");
    insert(ht, "banana", "yellow");
    insert(ht, "grape", "purple");

    printf("Search for 'banana': %s\n", search(ht, "banana"));

    deleteItem(ht, "banana");

    printf("Search for 'banana' after deletion: %s\n", search(ht, "banana"));

    freeHashTable(ht);
    return 0;
}