#include <iostream>
#include <string>
#include <gmpxx.h>

void generate_keys(mpz_class &n, mpz_class &d, mpz_class &e, int bits) {
    gmp_randclass r(gmp_randinit_default);
    r.seed(time(NULL));

    mpz_class p = r.get_z_bits(bits / 2);
    mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());

    mpz_class q = r.get_z_bits(bits / 2);
    mpz_nextprime(q.get_mpz_t(), q.get_mpz_t());

    n = p * q;

    mpz_class phi = (p - 1) * (q - 1);

    e = 65537;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());
}

void encrypt(mpz_class &ciphertext, const mpz_class &message, const mpz_class &e, const mpz_class &n) {
    mpz_powm(ciphertext.get_mpz_t(), message.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
}

void decrypt(mpz_class &decrypted, const mpz_class &ciphertext, const mpz_class &d, const mpz_class &n) {
    mpz_powm(decrypted.get_mpz_t(), ciphertext.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
}

int main() {
    mpz_class n, d, e, plaintext, ciphertext, decrypted;

    generate_keys(n, d, e, 1024);
    
    std::string message = "Hello RSA!";
    plaintext = mpz_class(message.c_str());

    std::cout << "Plaintext: " << plaintext << std::endl;

    encrypt(ciphertext, plaintext, e, n);
    std::cout << "Encrypted: " << ciphertext << std::endl;

    decrypt(decrypted, ciphertext, d, n);
    std::cout << "Decrypted: " << decrypted.get_str() << std::endl;

    return 0;
}