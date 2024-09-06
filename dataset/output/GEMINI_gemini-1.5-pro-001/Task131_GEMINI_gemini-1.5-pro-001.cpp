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
    std::cout << deserializedData.dump(2) << std::endl; // Pretty print with indentation
  } catch (const json::parse_error& e) {
    std::cerr << "Error deserializing data: " << e.what() << std::endl;
  }

  return 0;
}