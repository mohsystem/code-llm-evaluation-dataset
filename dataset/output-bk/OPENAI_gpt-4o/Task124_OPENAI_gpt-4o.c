#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

char* base64_encode(const char* input, int length) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;
    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);
    char *buff = (char *)malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;
    BIO_free_all(b64);
    return buff;
}

char* base64_decode(char* input, int length) {
    BIO *b64, *bmem;
    char *buffer = (char *)malloc(length);
    memset(buffer, 0, length);
    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);
    BIO_free_all(b64);
    return buffer;
}

int main() {
    char* sensitive_data = "4111-1111-1111-1111";
    char* encoded = base64_encode(sensitive_data, strlen(sensitive_data));
    printf("Encoded Data (C): %s
", encoded);
    char* decoded = base64_decode(encoded, strlen(encoded));
    printf("Decoded Data (C): %s
", decoded);
    free(encoded);
    free(decoded);
    return 0;
}