
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void generate_keys(mpz_t n, mpz_t e, mpz_t d, int bits) {
    mpz_t p, q, phi, gcd;
    gmp_randstate_t state;

    mpz_inits(p, q, phi, gcd, NULL);
    gmp_randinit_default(state);

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

    mpz_clears(p, q, phi, gcd, NULL);
    gmp_randclear(state);
}

void encrypt(mpz_t c, mpz_t m, mpz_t e, mpz_t n) {
    mpz_powm(c, m, e, n);
}

void decrypt(mpz_t m, mpz_t c, mpz_t d, mpz_t n) {
    mpz_powm(m, c, d, n);
}

int main() {
    mpz_t n, e, d, m, c;
    mpz_inits(n, e, d, m, c, NULL);

    generate_keys(n, e, d, 1024);

    char message[] = "Hello, RSA!";
    mpz_import(m, strlen(message), 1, sizeof(char), 0, 0, message);

    encrypt(c, m, e, n);
    gmp_printf("Encrypted: %Zd\
", c);

    decrypt(m, c, d, n);
    char decrypted[100];
    mpz_export(decrypted, NULL, 1, sizeof(char), 0, 0, m);
    printf("Decrypted: %s\
", decrypted);

    mpz_clears(n, e, d, m, c, NULL);
    return 0;
}
