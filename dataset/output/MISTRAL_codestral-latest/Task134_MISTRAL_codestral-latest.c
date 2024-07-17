// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* keyName;
    char* keyValue;
} KeyPair;

typedef struct {
    KeyPair* keys;
    int size;
    int capacity;
} CryptoKeyManager;

CryptoKeyManager* createCryptoKeyManager() {
    CryptoKeyManager* manager = (CryptoKeyManager*)malloc(sizeof(CryptoKeyManager));
    manager->size = 0;
    manager->capacity = 10;
    manager->keys = (KeyPair*)malloc(sizeof(KeyPair) * manager->capacity);
    return manager;
}

void addKey(CryptoKeyManager* manager, const char* keyName, const char* keyValue) {
    if (manager->size == manager->capacity) {
        manager->capacity *= 2;
        manager->keys = (KeyPair*)realloc(manager->keys, sizeof(KeyPair) * manager->capacity);
    }
    manager->keys[manager->size].keyName = strdup(keyName);
    manager->keys[manager->size].keyValue = strdup(keyValue);
    manager->size++;
}

char* getKey(CryptoKeyManager* manager, const char* keyName) {
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->keys[i].keyName, keyName) == 0) {
            return manager->keys[i].keyValue;
        }
    }
    return NULL;
}

void removeKey(CryptoKeyManager* manager, const char* keyName) {
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->keys[i].keyName, keyName) == 0) {
            free(manager->keys[i].keyName);
            free(manager->keys[i].keyValue);
            for (int j = i; j < manager->size - 1; j++) {
                manager->keys[j] = manager->keys[j + 1];
            }
            manager->size--;
            break;
        }
    }
}

void freeCryptoKeyManager(CryptoKeyManager* manager) {
    for (int i = 0; i < manager->size; i++) {
        free(manager->keys[i].keyName);
        free(manager->keys[i].keyValue);
    }
    free(manager->keys);
    free(manager);
}