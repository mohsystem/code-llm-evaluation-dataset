#include <stdbool.h>
#include <string.h>

bool checkFlush(char* table[], int table_size, char* hand[], int hand_size) {
    int suits[4] = {0};
    for (int i = 0; i < table_size; i++) {
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
    for (int i = 0; i < hand_size; i++) {
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
            return true;
        }
    }
    return false;
}