#include <iostream>
#include <string>
#include <regex>

std::string clean_phone_number(const std::string& phone_number) {
  std::string cleaned_number = std::regex_replace(phone_number, std::regex("[^0-9]"), "");
  if (cleaned_number.length() == 11 && cleaned_number[0] == '1') {
    return cleaned_number.substr(1);
  }
  return (cleaned_number.length() == 10) ? cleaned_number : "";
}

int main() {
  std::string phone_numbers[] = {
    "+1 (613)-995-0253",
    "613-995-0253",
    "1 613 995 0253",
    "613.995.0253",
    "123456789012"  // Invalid phone number
  };

  for (const std::string& number : phone_numbers) {
    std::string cleaned_number = clean_phone_number(number);
    if (cleaned_number.length() > 0) {
      std::cout << "Original: " << number << " -> Cleaned: " << cleaned_number << std::endl;
    } else {
      std::cout << "Invalid phone number: " << number << std::endl;
    }
  }

  return 0;
}