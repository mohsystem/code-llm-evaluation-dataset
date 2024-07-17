
#include <stdio.h>

void createPhoneNumber(int numbers[], char *phone_number) {
    sprintf(phone_number, "(%d%d%d) %d%d%d-%d%d%d%d",
        numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
        numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char phone_number[15];
    createPhoneNumber(numbers, phone_number);
    printf("%s\
", phone_number);
    return 0;
}
