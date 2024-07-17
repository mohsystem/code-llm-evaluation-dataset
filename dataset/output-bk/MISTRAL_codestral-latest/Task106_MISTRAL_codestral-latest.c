#include <gmp.h>

void rsa_init(mpz_t p, mpz_t q, mpz_t N, mpz_t phi, mpz_t e, mpz_t d) {
    gmp_randstate_t state;
    gmp_randinit_default(state);

    mpz_urandomb(p, state, 1024);
    mpz_nextprime(p, p);
    mpz_urandomb(q, state, 1024);
    mpz_nextprime(q, q);

    mpz_mul(N, p, q);
    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);
    mpz_mul(phi, p, q);

    mpz_urandomb(e, state, 1024 / 2);
    mpz_nextprime(e, e);
    while (mpz_gcd_ui(phi, mpz_get_ui(e)) > 1 && mpz_cmp(e, phi) < 0) {
        mpz_add_ui(e, e, 1);
    }

    mpz_invert(d, e, phi);

    gmp_randclear(state);
}

void rsa_encrypt(mpz_t encrypted, mpz_t message, mpz_t e, mpz_t N) {
    mpz_powm(encrypted, message, e, N);
}

void rsa_decrypt(mpz_t decrypted, mpz_t encrypted, mpz_t d, mpz_t N) {
    mpz_powm(decrypted, encrypted, d, N);
}