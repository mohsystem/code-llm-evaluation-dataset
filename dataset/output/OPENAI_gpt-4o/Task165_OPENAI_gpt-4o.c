#include <stdio.h>
#include <string.h>

int checkFlush(const char* table[], const char* hand[], size_t table_len, size_t hand_len) {
    int suits[4] = {0}; // 0: S, 1: H, 2: D, 3: C
    
    for (size_t i = 0; i < table_len; i++) {
        if (strstr(table[i], "_S") != NULL) suits[0]++;
        else if (strstr(table[i], "_H") != NULL) suits[1]++;
        else if (strstr(table[i], "_D") != NULL) suits[2]++;
        else if (strstr(table[i], "_C") != NULL) suits[3]++;
    }

    for (size_t i = 0; i < hand_len; i++) {
        if (strstr(hand[i], "_S") != NULL) suits[0]++;
        else if (strstr(hand[i], "_H") != NULL) suits[1]++;
        else if (strstr(hand[i], "_D") != NULL) suits[2]++;
        else if (strstr(hand[i], "_C") != NULL) suits[3]++;
    }

    for (int i = 0; i < 4; i++) {
        if (suits[i] >= 5) return 1;
    }

    return 0;
}

int main() {
    const char* table1[] = {"A_S", "J_H", "7_D", "8_D", "10_D"};
    const char* hand1[] = {"J_D", "3_D"};
    const char* table2[] = {"10_S", "7_S", "9_H", "4_S", "3_S"};
    const char* hand2[] = {"K_S", "Q_S"};
    const char* table3[] = {"3_S", "10_H", "10_D", "10_C", "10_S"};
    const char* hand3[] = {"3_S", "4_D"};

    printf(checkFlush(table1, hand1, 5, 2) ? "true\n" : "false\n"); // ➞ true
    printf(checkFlush(table2, hand2, 5, 2) ? "true\n" : "false\n"); // ➞ true
    printf(checkFlush(table3, hand3, 5, 2) ? "true\n" : "false\n"); // ➞ false

    return 0;
}