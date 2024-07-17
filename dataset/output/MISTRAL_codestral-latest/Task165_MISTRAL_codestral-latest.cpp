#include <vector>
#include <string>

bool checkFlush(std::vector<std::string> table, std::vector<std::string> hand) {
    int suits[4] = {0};
    for (const std::string& card : table) {
        char suit = card.back();
        switch (suit) {
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
    for (const std::string& card : hand) {
        char suit = card.back();
        switch (suit) {
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