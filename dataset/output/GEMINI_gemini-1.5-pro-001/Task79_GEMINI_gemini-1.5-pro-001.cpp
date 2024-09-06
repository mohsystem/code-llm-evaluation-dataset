#include <iostream>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/secblock.h>

using namespace std;
using namespace CryptoPP;

string encryptMessage(const string& message, const string& key) {
    // Create a cipher for encryption
    AES::Encryption aesEncryption((byte*)key.c_str(), AES::DEFAULT_KEYLENGTH);
    CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte*)key.c_str());

    // Encrypt the message
    string encryptedMessage;
    StringSource(message, true,
        new StreamTransformationFilter(cbcEncryption,
            new StringSink(encryptedMessage),
            StreamTransformationFilter::PKCS_PADDING));

    // Convert the encrypted message to hexadecimal string
    string encoded;
    HexEncoder encoder(new StringSink(encoded));
    encoder.Put((const byte*)encryptedMessage.data(), encryptedMessage.size());
    encoder.MessageEnd();

    return encoded;
}