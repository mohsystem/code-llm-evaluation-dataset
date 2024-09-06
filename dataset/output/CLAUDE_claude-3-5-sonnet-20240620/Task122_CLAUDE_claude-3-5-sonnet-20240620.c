
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define SALT_SIZE 16
#define KEY_SIZE 32
#define ITERATIONS 100000

void hash_password(const char* password, unsigned char* result) {
    unsigned char salt[SALT_SIZE];
    RAND_bytes(salt, SALT_SIZE);

    unsigned char key[KEY_SIZE];
    PKCS5_PBKDF2_HMAC(password, strlen(password), salt, SALT_SIZE,
                      ITERATIONS, EVP_sha256(), KEY_SIZE, key);

    memcpy(result, salt, SALT_SIZE);
    memcpy(result + SALT_SIZE, key, KEY_SIZE);
}

void signup() {
    char username[100], password[100];
    printf("Enter username: ");
    scanf("%99s", username);
    printf("Enter password: ");
    scanf("%99s", password);

    unsigned char hashed_password[SALT_SIZE + KEY_SIZE];
    hash_password(password, hashed_password);

    FILE* file = fopen("passwords.txt", "ab");
    if (file == NULL) {
        printf("Error opening file.\\n");
        return;
    }

    fprintf(file, "%s:", username);
    fwrite(hashed_password, 1, SALT_SIZE + KEY_SIZE, file);
    fprintf(file, "\\n");
    fclose(file);

    printf("Signup successful!\\n");
}

int main() {
    OpenSSL_add_all_algorithms();
    signup();
    EVP_cleanup();
    return 0;
}
