#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

std::string generate_random_string(size_t length) {
  const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

  std::string random_string;
  random_string.reserve(length);

  for (size_t i = 0; i < length; ++i) {
    random_string += characters[distribution(generator)];
  }

  return random_string;
}

std::string to_unicode(const std::string& str) {
  std::string result;
  for (char c : str) {
    result += "\\u" + std::hex + std::setw(4) + std::setfill('0') + static_cast<int>(c);
  }
  return result;
}

int main() {
  // Create a temporary file
  std::string filename = std::tmp_namespaced_path("/tmp/tempfile-XXXXXX");
  std::ofstream temp_file(filename);
  if (!temp_file.is_open()) {
    std::cerr << "Failed to create temporary file." << std::endl;
    return 1;
  }

  // Generate random string and convert to Unicode
  std::string random_str = generate_random_string(10);
  std::string unicode_str = to_unicode(random_str);

  // Write to file
  temp_file << unicode_str;

  // Close file and print filename
  temp_file.close();
  std::cout << filename << std::endl;
  
  return 0;
}