#include <iostream>
#include <random>
#include <string>

std::string generate_token(size_t length = 32) {
  const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(0, characters.size() - 1);

  std::string token;
  token.reserve(length);

  for (size_t i = 0; i < length; ++i) {
    token += characters[distribution(generator)];
  }

  return token;
}

int main() {
  std::cout << generate_token() << std::endl;
  return 0;
}