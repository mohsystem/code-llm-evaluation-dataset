#include <stdio.h>

int checkFlush(char* table[7], char* hand[2]) {
    int suits[4] = {0};
    for (int i = 0; i < 7; i++) {
        char suit = table[i][strlen(table[i]) - 1];
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
    for (int i = 0; i < 2; i++) {
        char suit = hand[i][strlen(hand[i]) - 1];
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
    char* table[7] = {"A_S", "J_H", "7_D", "8_D", "10_D", "J_D", "3_D"};
    char* hand[2] = {"J_D", "3_D"};
    printf("%s
", checkFlush(table, hand) ? "true" : "false");
    return 0;
}