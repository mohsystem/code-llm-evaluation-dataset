#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct HashNode {
    int key;
    char value[50];
    struct HashNode* next;
} HashNode;

HashNode* hashTable[SIZE];

unsigned int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, char* value) {
    unsigned int hashKey = hashFunction(key);
    HashNode* newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (hashTable[hashKey] == NULL) {
        hashTable[hashKey] = newNode;
    } else {
        HashNode* temp = hashTable[hashKey];
        while (temp->next != NULL) {
            if (temp->key == key) {
                strcpy(temp->value, value);
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(int key) {
    unsigned int hashKey = hashFunction(key);
    HashNode* temp = hashTable[hashKey];
    HashNode* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        hashTable[hashKey] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

char* search(int key) {
    unsigned int hashKey = hashFunction(key);
    HashNode* temp = hashTable[hashKey];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return "None";
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(1, "one");
    insert(2, "two");
    printf("%s
", search(1)); // should print "one"
    delete(1);
    printf("%s
", search(1)); // should print "None"

    return 0;
}