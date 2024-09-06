#include <iostream>
#include <random>
#include <string>

std::string generate_session_id(size_t length = 16) {
  const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distribution(0, characters.size() - 1);

  std::string session_id;
  session_id.reserve(length);

  for (size_t i = 0; i < length; ++i) {
    session_id += characters[distribution(generator)];
  }

  return session_id;
}