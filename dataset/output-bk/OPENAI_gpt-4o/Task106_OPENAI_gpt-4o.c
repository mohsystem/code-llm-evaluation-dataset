#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void generate_keys(mpz_t n, mpz_t d, mpz_t e, int bits) {
    mpz_t p, q, phi, temp;
    mpz_inits(p, q, phi, temp, NULL);
    gmp_randstate_t state;

    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));
    
    mpz_urandomb(p, state, bits / 2);
    mpz_nextprime(p, p);

    mpz_urandomb(q, state, bits / 2);
    mpz_nextprime(q, q);

    mpz_mul(n, p, q);
    
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(phi, p, q);

    mpz_set_ui(e, 65537);
    mpz_invert(d, e, phi);

    mpz_clears(p, q, phi, temp, NULL);
    gmp_randclear(state);
}

void encrypt(mpz_t r, mpz_t m, mpz_t e, mpz_t n) {
    mpz_powm(r, m, e, n);
}

void decrypt(mpz_t r, mpz_t c, mpz_t d, mpz_t n) {
    mpz_powm(r, c, d, n);
}

int main() {
    mpz_t n, d, e, plaintext, ciphertext, decrypted;
    mpz_inits(n, d, e, plaintext, ciphertext, decrypted, NULL);

    generate_keys(n, d, e, 1024);

    char message[] = "Hello RSA!";
    mpz_import(plaintext, strlen(message), 1, 1, 0, 0, message);

    gmp_printf("Plaintext: %Zd
", plaintext);

    encrypt(ciphertext, plaintext, e, n);
    gmp_printf("Encrypted: %Zd
", ciphertext);

    decrypt(decrypted, ciphertext, d, n);
    int count;
    unsigned char* decrypted_str = mpz_export(NULL, &count, 1, 1, 0, 0, decrypted);
    printf("Decrypted: %.*s
", count, decrypted_str);
    
    mpz_clears(n, d, e, plaintext, ciphertext, decrypted, NULL);
    free(decrypted_str);

    return 0;
}