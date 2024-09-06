#include <stdio.h>
#include <string.h>

int checkFlush(char* table[], char* hand[]) {
    int suits[4] = {0};
    for (int i = 0; i < 5; i++) {
        switch (table[i][strlen(table[i]) - 1]) {
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
        switch (hand[i][strlen(hand[i]) - 1]) {
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
    char* table[] = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    char* hand[] = {"J_D", "3_D"};
    printf("%d\n", checkFlush(table, hand));
    return 0;
}