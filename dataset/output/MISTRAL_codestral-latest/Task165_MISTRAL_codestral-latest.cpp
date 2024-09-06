#include <vector>
#include <string>
#include <unordered_map>

bool checkFlush(std::vector<std::string> table, std::vector<std::string> hand) {
    std::unordered_map<char, int> suitCount;
    for (const auto& card : table)
        suitCount[card.back()]++;
    for (const auto& card : hand)
        suitCount[card.back()]++;
    for (char suit : "SHDC")
        if (suitCount[suit] >= 5)
            return true;
    return false;
}