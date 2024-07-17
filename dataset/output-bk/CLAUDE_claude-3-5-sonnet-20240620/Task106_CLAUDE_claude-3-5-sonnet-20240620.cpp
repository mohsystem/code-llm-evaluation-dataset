
#include <iostream>
#include <string>
#include <gmpxx.h>

class RSA {
private:
    mpz_class n, d, e;

public:
    RSA(int bitLength) {
        gmp_randclass rnd(gmp_randinit_default);
        rnd.seed(time(NULL));

        mpz_class p = rnd.get_z_bits(bitLength / 2);
        mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());

        mpz_class q = rnd.get_z_bits(bitLength / 2);
        mpz_nextprime(q.get_mpz_t(), q.get_mpz_t());

        n = p * q;
        mpz_class phi = (p - 1) * (q - 1);

        e = 65537;
        mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());
    }

    mpz_class encrypt(const mpz_class& message) {
        return mpz_class(mpz_powm(NULL, message.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t()));
    }

    mpz_class decrypt(const mpz_class& encrypted) {
        return mpz_class(mpz_powm(NULL, encrypted.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t()));
    }
};

int main() {
    RSA rsa(1024);
    std::string message = "Hello, RSA!";
    mpz_class plaintext;
    mpz_import(plaintext.get_mpz_t(), message.size(), 1, sizeof(char), 0, 0, message.c_str());

    mpz_class ciphertext = rsa.encrypt(plaintext);
    mpz_class decrypted = rsa.decrypt(ciphertext);

    std::cout << "Original: " << message << std::endl;
    std::cout << "Encrypted: " << ciphertext << std::endl;

    char decrypted_str[100];
    mpz_export(decrypted_str, NULL, 1, sizeof(char), 0, 0, decrypted.get_mpz_t());
    std::cout << "Decrypted: " << decrypted_str << std::endl;

    return 0;
}
