#include <gmpxx.h>

void rsa_init(mpz_class& p, mpz_class& q, mpz_class& N, mpz_class& phi, mpz_class& e, mpz_class& d) {
    gmp_randclass r(gmp_randinit_default);

    p = r.get_z_bits(1024);
    p = mpz_class(p.get_mpz_t()).nextprime();
    q = r.get_z_bits(1024);
    q = mpz_class(q.get_mpz_t()).nextprime();

    N = p * q;
    phi = (p - 1) * (q - 1);

    e = r.get_z_bits(1024 / 2);
    e = mpz_class(e.get_mpz_t()).nextprime();
    while (gcd(phi, e) > 1 && e < phi) {
        e++;
    }

    d = invert(e, phi);
}

void rsa_encrypt(mpz_class& encrypted, mpz_class& message, mpz_class& e, mpz_class& N) {
    powm(encrypted, message, e, N);
}

void rsa_decrypt(mpz_class& decrypted, mpz_class& encrypted, mpz_class& d, mpz_class& N) {
    powm(decrypted, encrypted, d, N);
}