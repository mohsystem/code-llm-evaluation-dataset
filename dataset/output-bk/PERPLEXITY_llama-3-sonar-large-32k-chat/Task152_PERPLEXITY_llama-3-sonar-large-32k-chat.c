#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

int hash(int key, int size) {
    return key % size;
}

void insert(HashTable* ht, int key, char* value) {
    int index = hash(key, ht->size);
    Node* node = ht->table[index];
    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            return;
        }
        if (node->next == NULL) {
            node->next = (Node*)malloc(sizeof(Node));
            node->next->key = key;
            node->next->value = value;
            node->next->next = NULL;
            return;
        }
        node = node->next;
    }
    ht->table[index] = (Node*)malloc(sizeof(Node));
    ht->table[index]->key = key;
    ht->table[index]->value = value;
    ht->table[index]->next = NULL;
}

void delete(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    Node* node = ht->table[index];
    Node* prev = NULL;
    while (node != NULL) {
        if (node->key == key) {
            if (prev == NULL) {
                ht->table[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

char* search(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    Node* node = ht->table[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

int main() {
    HashTable ht;
    ht.size = 10;
    ht.table = (Node**)malloc(ht.size * sizeof(Node*));
    for (int i = 0; i < ht.size; i++) {
        ht.table[i] = NULL;
    }
    insert(&ht, 1, "one");
    insert(&ht, 11, "eleven");
    insert(&ht, 21, "twenty one");
    printf("%s
", search(&ht, 1));  // Output: one
    printf("%s
", search(&ht, 11));  // Output: eleven
    printf("%s
", search(&ht, 21));  // Output: twenty one
    delete(&ht, 11);
    printf("%s
", search(&ht, 11));  // Output: (null)
    return 0;
}