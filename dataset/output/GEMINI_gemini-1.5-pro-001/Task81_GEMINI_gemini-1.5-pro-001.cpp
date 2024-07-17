#include <iostream>
#include <fstream>
#include <string>
#include <openssl/sha.h>

using namespace std;

bool check_certificate_hash(const string& certificate_path, const string& expected_hash) {
  ifstream certificate_file(certificate_path, ios::binary);
  if (!certificate_file.is_open()) {
    cerr << "Error: Could not open certificate file: " << certificate_path << endl;
    return false;
  }

  unsigned char buffer[4096];
  SHA256_CTX sha256_ctx;
  SHA256_Init(&sha256_ctx);

  while (!certificate_file.eof()) {
    certificate_file.read((char*)buffer, sizeof(buffer));
    size_t bytes_read = certificate_file.gcount();
    SHA256_Update(&sha256_ctx, buffer, bytes_read);
  }

  unsigned char calculated_hash[SHA256_DIGEST_LENGTH];
  SHA256_Final(calculated_hash, &sha256_ctx);

  certificate_file.close();

  string calculated_hash_str;
  calculated_hash_str.reserve(SHA256_DIGEST_LENGTH * 2);
  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    calculated_hash_str += string_format("%02x", calculated_hash[i]);
  }

  return calculated_hash_str == expected_hash;
}

int main() {
  string certificate_file;
  string expected_hash;

  cout << "Enter the path to the SSL certificate file: ";
  cin >> certificate_file;

  cout << "Enter the expected SHA-256 hash: ";
  cin >> expected_hash;

  if (check_certificate_hash(certificate_file, expected_hash)) {
    cout << "Certificate hash matches!" << endl;
  } else {
    cout << "Certificate hash does not match." << endl;
  }

  return 0;
}