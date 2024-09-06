#include <stdio.h>
#include <string.h>

int checkFlush(char table[5][4], char hand[2][4]) {
  int suits[4] = {0}; // S, H, D, C
  for (int i = 0; i < 5; i++) {
    if (table[i][2] == 'S') suits[0]++;
    else if (table[i][2] == 'H') suits[1]++;
    else if (table[i][2] == 'D') suits[2]++;
    else if (table[i][2] == 'C') suits[3]++;
  }
  for (int i = 0; i < 2; i++) {
    if (hand[i][2] == 'S') suits[0]++;
    else if (hand[i][2] == 'H') suits[1]++;
    else if (hand[i][2] == 'D') suits[2]++;
    else if (hand[i][2] == 'C') suits[3]++;
  }
  for (int i = 0; i < 4; i++) {
    if (suits[i] >= 5) {
      return 1; // true
    }
  }
  return 0; // false
}