#include <iostream>
#include <random>

std::string generateRandomString(int length) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<char> distribution('a', 'z');

  std::string randomString;
  for (int i = 0; i < length; ++i) {
    char randomChar = distribution(generator);
    randomString += (i % 2 == 0) ? randomChar : toupper(randomChar);
  }

  return randomString;
}