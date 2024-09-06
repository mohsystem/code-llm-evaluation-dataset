#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool checkFlush(std::vector<std::string> table, std::vector<std::string> hand) {
    int suits[4] = {0};
    for (const auto& card : table) {
        switch (card.back()) {
            case 'S':
                suits[0]++;
                break;
            case 'H':
                suits[1]++;
                break;
            case 'D':
                suits[2]++;
                break;
            case 'C':
                suits[3]++;
                break;
        }
    }
    for (const auto& card : hand) {
        switch (card.back()) {
            case 'S':
                suits[0]++;
                break;
            case 'H':
                suits[1]++;
                break;
            case 'D':
                suits[2]++;
                break;
            case 'C':
                suits[3]++;
                break;
        }
    }
    for (int suit : suits) {
        if (suit >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::string> table = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    std::vector<std::string> hand = {"J_D", "3_D"};
    std::cout << std::boolalpha << checkFlush(table, hand) << std::endl;
    return 0;
}