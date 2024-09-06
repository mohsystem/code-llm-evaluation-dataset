
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool checkFlush(char table[][4], int tableSize, char hand[][4], int handSize) {
    int suits[4] = {0}; // S, H, D, C
    
    for (int i = 0; i < tableSize; i++) {
        switch(table[i][2]) {
            case 'S': suits[0]++; break;
            case 'H': suits[1]++; break;
            case 'D': suits[2]++; break;
            case 'C': suits[3]++; break;
        }
    }
    
    for (int i = 0; i < handSize; i++) {
        switch(hand[i][2]) {
            case 'S': suits[0]++; break;
            case 'H': suits[1]++; break;
            case 'D': suits[2]++; break;
            case 'C': suits[3]++; break;
        }
    }
    
    int max_suit = MAX(MAX(suits[0], suits[1]), MAX(suits[2], suits[3]));
    return max_suit >= 5;
}

int main() {
    char table1[][4] = {"A_S", "J_H", "7_D", "8_D", "10D"};
    char hand1[][4] = {"J_D", "3_D"};
    printf("%s\\n", checkFlush(table1, 5, hand1, 2) ? "true" : "false");  // true
    
    char table2[][4] = {"10S", "7_S", "9_H", "4_S", "3_S"};
    char hand2[][4] = {"K_S", "Q_S"};
    printf("%s\\n", checkFlush(table2, 5, hand2, 2) ? "true" : "false");  // true
    
    char table3[][4] = {"3_S", "10H", "10D", "10C", "10S"};
    char hand3[][4] = {"3_S", "4_D"};
    printf("%s\\n", checkFlush(table3, 5, hand3, 2) ? "true" : "false");  // false
    
    return 0;
}
