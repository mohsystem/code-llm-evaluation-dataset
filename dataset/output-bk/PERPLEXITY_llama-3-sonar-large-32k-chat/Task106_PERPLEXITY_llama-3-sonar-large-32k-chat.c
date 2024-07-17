#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void generate_keys(mpz_t p, mpz_t q, mpz_t n, mpz_t phi, mpz_t e, mpz_t d) {
    mpz_init_set_ui(p, 61); // prime number
    mpz_init_set_ui(q, 53); // prime number
    mpz_mul(n, p, q);
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(phi, p, q);
    mpz_init_set_ui(e, 17); // coprime with phi
    mpz_invert(d, e, phi);
}

void encrypt(mpz_t msg, mpz_t encrypted, mpz_t e, mpz_t n) {
    mpz_powm(encrypted, msg, e, n);
}

void decrypt(mpz_t encrypted, mpz_t decrypted, mpz_t d, mpz_t n) {
    mpz_powm(decrypted, encrypted, d, n);
}

int main() {
    mpz_t p, q, n, phi, e, d, msg, encrypted, decrypted;
    mpz_init(msg);
    mpz_init(encrypted);
    mpz_init(decrypted);
    generate_keys(p, q, n, phi, e, d);
    printf("Enter a message (number): ");
    scanf("%Zd", msg);
    encrypt(msg, encrypted, e, n);
    printf("Encrypted: %Zd
", encrypted);
    decrypt(encrypted, decrypted, d, n);
    printf("Decrypted: %Zd
", decrypted);
    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(n);
    mpz_clear(phi);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(msg);
    mpz_clear(encrypted);
    mpz_clear(decrypted);
    return 0;
}