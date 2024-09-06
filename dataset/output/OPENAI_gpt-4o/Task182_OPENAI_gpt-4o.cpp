#include <iostream>
#include <vector>
#include <regex>

std::string cleanNumber(std::string number) {
    number = std::regex_replace(number, std::regex("[^0-9]"), "");
    if (number.length() == 11 && number[0] == '1') {
        number = number.substr(1);
    }
    return number;
}

int main() {
    std::vector<std::string> numbers = {"+1 (613)-995-0253", "613-995-0253", "1 613 995 0253", "613.995.0253"};
    std::vector<std::string> cleanedNumbers;

    for (auto& number : numbers) {
        cleanedNumbers.push_back(cleanNumber(number));
    }

    for (auto& cleanedNumber : cleanedNumbers) {
        std::cout << cleanedNumber << std::endl;
    }

    return 0;
}