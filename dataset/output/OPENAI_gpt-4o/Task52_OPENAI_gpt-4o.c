#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void writeKeyToFile(const unsigned char* key, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp != NULL) {
        fwrite(key, 1, AES_BLOCK_SIZE, fp);
        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open file %s for writing\n", filename);
    }
}

void readKeyFromFile(unsigned char* key, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp != NULL) {
        fread(key, 1, AES_BLOCK_SIZE, fp);
        fclose(fp);
    } else {
        fprintf(stderr, "Failed to open file %s for reading\n", filename);
    }
}

void encryptFile(const unsigned char* key, const char* input_filename, const char* output_filename) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);

    FILE* ifp = fopen(input_filename, "rb");
    FILE* ofp = fopen(output_filename, "wb");

    unsigned char indata[AES_BLOCK_SIZE];
    unsigned char outdata[AES_BLOCK_SIZE];

    while (fread(indata, 1, AES_BLOCK_SIZE, ifp) > 0) {
        AES_encrypt(indata, outdata, &encryptKey);
        fwrite(outdata, 1, AES_BLOCK_SIZE, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

void decryptFile(const unsigned char* key, const char* input_filename, const char* output_filename) {
    AES_KEY decryptKey;
    AES_set_decrypt_key(key, 128, &decryptKey);

    FILE* ifp = fopen(input_filename, "rb");
    FILE* ofp = fopen(output_filename, "wb");

    unsigned char indata[AES_BLOCK_SIZE];
    unsigned char outdata[AES_BLOCK_SIZE];

    while (fread(indata, 1, AES_BLOCK_SIZE, ifp) > 0) {
        AES_decrypt(indata, outdata, &decryptKey);
        fwrite(outdata, 1, AES_BLOCK_SIZE, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

int main() {
    const char* keyfile = "filekey.key";
    const char* input_filename = "test.txt";
    const char* encrypted_filename = "test.encrypted";
    const char* decrypted_filename = "test.decrypted";

    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);
    writeKeyToFile(key, keyfile);

    encryptFile(key, input_filename, encrypted_filename);

    unsigned char loaded_key[AES_BLOCK_SIZE];
    readKeyFromFile(loaded_key, keyfile);
    decryptFile(loaded_key, encrypted_filename, decrypted_filename);

    return 0;
}