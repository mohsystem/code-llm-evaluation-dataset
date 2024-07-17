
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CARDS 7

bool checkFlush(const char* table[], int tableSize, const char* hand[], int handSize) {
    int suits[4] = {0};  // S, H, D, C
    
    for (int i = 0; i < tableSize; i++) {
        char suit = table[i][strlen(table[i]) - 1];
        if (suit == \'S\') suits[0]++;
        else if (suit == \'H\') suits[1]++;
        else if (suit == \'D\') suits[2]++;
        else if (suit == \'C\') suits[3]++;
    }
    
    for (int i = 0; i < handSize; i++) {
        char suit = hand[i][strlen(hand[i]) - 1];
        if (suit == \'S\') suits[0]++;
        else if (suit == \'H\') suits[1]++;
        else if (suit == \'D\') suits[2]++;
        else if (suit == \'C\') suits[3]++;
    }
    
    for (int i = 0; i < 4; i++) {
        if (suits[i] >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    const char* table1[] = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    const char* hand1[] = {"J_D", "3_D"};
    printf("%s\
", checkFlush(table1, 5, hand1, 2) ? "true" : "false");  // true
    
    const char* table2[] = {"10_S", "7_S", "9_H", "4_S", "3_S"};
    const char* hand2[] = {"K_S", "Q_S"};
    printf("%s\
", checkFlush(table2, 5, hand2, 2) ? "true" : "false");  // true
    
    const char* table3[] = {"3_S", "10_H", "10_D", "10_C", "10_S"};
    const char* hand3[] = {"3_S", "4_D"};
    printf("%s\
", checkFlush(table3, 5, hand3, 2) ? "true" : "false");  // false
    
    return 0;
}
