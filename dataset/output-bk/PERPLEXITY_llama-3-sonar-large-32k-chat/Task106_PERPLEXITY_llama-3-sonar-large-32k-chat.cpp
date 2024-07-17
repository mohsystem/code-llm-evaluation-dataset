#include <iostream>
#include <gmpxx.h>

void generate_keys(mpz_class& p, mpz_class& q, mpz_class& n, mpz_class& phi, mpz_class& e, mpz_class& d) {
    p = 61; // prime number
    q = 53; // prime number
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 17; // coprime with phi
    d = e.get_mod_inverse(phi);
}

void encrypt(const mpz_class& msg, mpz_class& encrypted, const mpz_class& e, const mpz_class& n) {
    encrypted = powm(msg, e, n);
}

void decrypt(const mpz_class& encrypted, mpz_class& decrypted, const mpz_class& d, const mpz_class& n) {
    decrypted = powm(encrypted, d, n);
}

int main() {
    mpz_class p, q, n, phi, e, d, msg, encrypted, decrypted;
    std::cout << "Enter a message (number): ";
    std::cin >> msg;
    generate_keys(p, q, n, phi, e, d);
    encrypt(msg, encrypted, e, n);
    std::cout << "Encrypted: " << encrypted << std::endl;
    decrypt(encrypted, decrypted, d, n);
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}