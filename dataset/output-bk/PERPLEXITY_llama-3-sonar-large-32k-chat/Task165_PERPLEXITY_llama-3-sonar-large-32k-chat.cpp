#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkFlush(vector<string> table, vector<string> hand) {
    int suits[4] = {0};
    for (string card : table) {
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
    for (string card : hand) {
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
    for (int count : suits) {
        if (count >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> table = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    vector<string> hand = {"J_D", "3_D"};
    cout << (checkFlush(table, hand) ? "true" : "false") << endl;
    return 0;
}