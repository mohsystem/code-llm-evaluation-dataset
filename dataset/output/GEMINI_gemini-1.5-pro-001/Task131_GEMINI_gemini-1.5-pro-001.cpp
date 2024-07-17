#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  std::string data;

  std::cout << "Enter the data to deserialize: ";
  std::getline(std::cin, data);

  try {
    json deserializedData = json::parse(data);
    std::cout << "Deserialized data: " << deserializedData.dump() << std::endl;
  } catch (const json::exception& e) {
    std::cerr << "Error: Invalid JSON data: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}