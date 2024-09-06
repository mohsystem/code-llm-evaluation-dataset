#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

bool checkFlush(std::vector<std::string> table, std::vector<std::string> hand) {
    std::unordered_map<char, int> suits = {{'S', 0}, {'H', 0}, {'D', 0}, {'C', 0}};
    
    for (const std::string& card : table) {
        suits[card.back()]++;
    }

    for (const std::string& card : hand) {
        suits[card.back()]++;
    }

    for (const auto& suit : suits) {
        if (suit.second >= 5) return true;
    }

    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << checkFlush({"A_S", "J_H", "7_D", "8_D", "10_D"}, {"J_D", "3_D"}) << std::endl; // ➞ true
    std::cout << checkFlush({"10_S", "7_S", "9_H", "4_S", "3_S"}, {"K_S", "Q_S"}) << std::endl; // ➞ true
    std::cout << checkFlush({"3_S", "10_H", "10_D", "10_C", "10_S"}, {"3_S", "4_D"}) << std::endl; // ➞ false
    return 0;
}