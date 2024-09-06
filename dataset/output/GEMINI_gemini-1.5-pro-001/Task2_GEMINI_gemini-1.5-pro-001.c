#include <stdio.h>

char* createPhoneNumber(int numbers[10]) {
  static char buffer[15];
  sprintf(buffer, "(%d%d%d) %d%d%d-%d%d%d%d", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
  return buffer;
}