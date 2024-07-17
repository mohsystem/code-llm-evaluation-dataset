#include <stdio.h>
#include <string.h>

int checkFlush(char tableCards[5][6], char handCards[2][6]) {
    int suits[4] = {0, 0, 0, 0}; // S, H, D, C
    char cards[7][6];
    
    for (int i = 0; i < 5; i++) {
        strcpy(cards[i], tableCards[i]);
    }
    for (int i = 0; i < 2; i++) {
        strcpy(cards[i + 5], handCards[i]);
    }
    
    for (int i = 0; i < 7; i++) {
        char suit = cards[i][strlen(cards[i]) - 1];
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
    
    for (int i = 0; i < 4; i++) {
        if (suits[i] >= 5) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char tableCards1[5][6] = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    char handCards1[2][6] = {"J_D", "3_D"};

    char tableCards2[5][6] = {"10_S", "7_S", "9_H", "4_S", "3_S"};
    char handCards2[2][6] = {"K_S", "Q_S"};

    char tableCards3[5][6] = {"3_S", "10_H", "10_D", "10_C", "10_S"};
    char handCards3[2][6] = {"3_S", "4_D"};
    
    printf("%d
", checkFlush(tableCards1, handCards1)); // ➞ true
    printf("%d
", checkFlush(tableCards2, handCards2)); // ➞ true
    printf("%d
", checkFlush(tableCards3, handCards3)); // ➞ false
    
    return 0;
}