
#include <iostream>
#include <string>
#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/filters.h>

using namespace CryptoPP;

int main() {
    std::string plaintext = "Text to be encrypted";
    std::string key = "0123456789abcdef";
    std::string iv = "0123456789abcdef";
    std::string ciphertext;

    try {
        CBC_Mode<AES>::Encryption e;
        e.SetKeyWithIV((byte*)key.c_str(), key.size(), (byte*)iv.c_str());

        StringSource s(plaintext, true, 
            new StreamTransformationFilter(e,
                new StringSink(ciphertext)
            )
        );

        std::cout << "Ciphertext: ";
        StringSource(ciphertext, true,
            new HexEncoder(
                new StringSink(std::cout)
            )
        );
        std::cout << std::endl;
    }
    catch(const Exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
