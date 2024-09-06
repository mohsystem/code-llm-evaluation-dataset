#include <stdio.h>
#include <string.h>

int checkFlush(char* table[], int tableSize, char* hand[], int handSize) {
    int suitCount[4] = {0};
    for (int i = 0; i < tableSize; i++) {
        char suit = table[i][strlen(table[i]) - 1];
        if (suit == 'S') suitCount[0]++;
        else if (suit == 'H') suitCount[1]++;
        else if (suit == 'D') suitCount[2]++;
        else if (suit == 'C') suitCount[3]++;
    }
    for (int i = 0; i < handSize; i++) {
        char suit = hand[i][strlen(hand[i]) - 1];
        if (suit == 'S') suitCount[0]++;
        else if (suit == 'H') suitCount[1]++;
        else if (suit == 'D') suitCount[2]++;
        else if (suit == 'C') suitCount[3]++;
    }
    for (int i = 0; i < 4; i++)
        if (suitCount[i] >= 5)
            return 1;
    return 0;
}