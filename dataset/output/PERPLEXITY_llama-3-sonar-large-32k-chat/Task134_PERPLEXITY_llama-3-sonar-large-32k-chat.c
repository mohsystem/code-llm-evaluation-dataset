code here:
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char** keys;
    int size;
} KeyManager;

KeyManager* key_manager_new() {
    KeyManager* manager = malloc(sizeof(KeyManager));
    manager->keys = NULL;
    manager->size = 0;
    return manager;
}

void key_manager_generate_key(KeyManager* manager, const char* username) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, username, strlen(username));
    SHA256_Final(hash, &sha256);
    char key[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(key + i * 2, "%02x", hash[i]);
    }
    manager->keys = realloc(manager->keys, (manager->size + 1) * sizeof(char*));
    manager->keys[manager->size] = malloc(strlen(username) + 1);
    strcpy(manager->keys[manager->size], username);
    manager->keys[manager->size + 1] = malloc(strlen(key) + 1);
    strcpy(manager->keys[manager->size + 1], key);
    manager->size += 2;
}

char* key_manager_get_key(KeyManager* manager, const char* username) {
    for (int i = 0; i < manager->size; i += 2) {
        if (strcmp(manager->keys[i], username) == 0) {
            return manager->keys[i + 1];
        }
    }
    return NULL;
}

void key_manager_delete_key(KeyManager* manager, const char* username) {
    for (int i = 0; i < manager->size; i += 2) {
        if (strcmp(manager->keys[i], username) == 0) {
            free(manager->keys[i]);
            free(manager->keys[i + 1]);
            for (int j = i; j < manager->size - 2; j += 2) {
                manager->keys[j] = manager->keys[j + 2];
                manager->keys[j + 1] = manager->keys[j + 3];
            }
            manager->size -= 2;
            manager->keys = realloc(manager->keys, manager->size * sizeof(char*));
            return;
        }
    }
}

int main() {
    KeyManager* manager = key_manager_new();
    key_manager_generate_key(manager, "user1");
    char* key = key_manager_get_key(manager, "user1");
    printf("%s
", key);
    key_manager_delete_key(manager, "user1");
    key = key_manager_get_key(manager, "user1");
    printf("%s
", key ? key : "NULL");
    return 0;
}