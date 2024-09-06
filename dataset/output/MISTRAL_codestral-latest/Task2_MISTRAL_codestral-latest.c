#include <stdio.h>

void create_phone_number(int numbers[10], char *phone_number) {
    sprintf(phone_number, "(%d%d%d) %d%d%d-%d%d%d%d", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
}