#include <iostream>
#include <vector>
#include <unordered_map>

bool checkFlush(std::vector<std::string> tableCards, std::vector<std::string> handCards) {
    std::unordered_map<char, int> suits = {{'S', 0}, {'H', 0}, {'D', 0}, {'C', 0}};
    tableCards.insert(tableCards.end(), handCards.begin(), handCards.end());
    
    for (const std::string& card : tableCards) {
        char suit = card.substr(card.find("_") + 1)[0];
        suits[suit]++;
    }
    
    for (const auto& suit : suits) {
        if (suit.second >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    std::cout << checkFlush({"A_S", "J_H", "7_D", "8_D", "10_D"}, {"J_D", "3_D"}) << "
"; // ➞ true
    std::cout << checkFlush({"10_S", "7_S", "9_H", "4_S", "3_S"}, {"K_S", "Q_S"}) << "
"; // ➞ true
    std::cout << checkFlush({"3_S", "10_H", "10_D", "10_C", "10_S"}, {"3_S", "4_D"}) << "
"; // ➞ false
    return 0;
}