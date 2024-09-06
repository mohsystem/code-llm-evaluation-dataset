#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

typedef struct {
    RSA* key;
} Key;

typedef struct {
    Key* keys;
    int size;
} KeyManager;

KeyManager* key_manager_new() {
    KeyManager* manager = (KeyManager*)malloc(sizeof(KeyManager));
    manager->keys = (Key*)malloc(sizeof(Key));
    manager->size = 0;
    return manager;
}

void key_manager_generate_key(KeyManager* manager, const char* keyName) {
    RSA* key = RSA_new();
    BIGNUM* exponent = BN_new();
    BN_set_word(exponent, 65537);
    RSA_generate_key_ex(key, 2048, exponent, nullptr);
    manager->keys[manager->size].key = key;
    manager->size++;
}

RSA* key_manager_get_key(KeyManager* manager, const char* keyName) {
    for (int i = 0; i < manager->size; i++) {
        // Assuming keyName is a simple string, not a secure way to store key names
        if (strcmp(keyName, "my_key") == 0) {
            return manager->keys[i].key;
        }
    }
    return nullptr;
}

void key_manager_delete_key(KeyManager* manager, const char* keyName) {
    for (int i = 0; i < manager->size; i++) {
        // Assuming keyName is a simple string, not a secure way to store key names
        if (strcmp(keyName, "my_key") == 0) {
            RSA_free(manager->keys[i].key);
            manager->size--;
            return;
        }
    }
}

char* key_manager_hash_key(KeyManager* manager, const char* keyName) {
    RSA* key = key_manager_get_key(manager, keyName);
    if (key != nullptr) {
        unsigned char buffer[256];
        unsigned int length = i2s_PublicKey(key, buffer);
        char keyString[length + 1];
        strncpy(keyString, (char*)buffer, length);
        keyString[length] = '\0';
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256((unsigned char*)keyString, strlen(keyString), hash);
        char hashString[SHA256_DIGEST_LENGTH * 2 + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(hashString + i * 2, "%02x", hash[i]);
        }
        return strdup(hashString);
    } else {
        return nullptr;
    }
}

int main() {
    KeyManager* manager = key_manager_new();
    const char* keyName = "my_key";
    key_manager_generate_key(manager, keyName);
    RSA* key = key_manager_get_key(manager, keyName);
    printf("Generated key for %s: ", keyName);
    char buffer[256];
    unsigned int length = i2s_PublicKey(key, buffer);
    printf("%s\n", buffer);
    char* hash = key_manager_hash_key(manager, keyName);
    printf("Hash of %s: %s\n", keyName, hash);
    free(hash);
    key_manager_delete_key(manager, keyName);
    printf("Key %s deleted: %p\n", keyName, key_manager_get_key(manager, keyName));
    return 0;
}