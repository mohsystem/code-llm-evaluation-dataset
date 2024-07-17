#include <iostream>
#include <random>
#include <string>

int generateRandomNumber(int min, int max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

std::string generateRandomToken(int length) {
  const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<std::size_t> distribution(0, characters.size() - 1);

  std::string token;
  for (int i = 0; i < length; ++i) {
    token += characters[distribution(generator)];
  }
  return token;
}

int main() {
  int randomNumber = generateRandomNumber(1, 10);
  std::cout << "Random number between 1 and 10: " << randomNumber << std::endl;

  std::string randomToken = generateRandomToken(20);
  std::cout << "Random token of length 20: " << randomToken << std::endl;

  return 0;
}