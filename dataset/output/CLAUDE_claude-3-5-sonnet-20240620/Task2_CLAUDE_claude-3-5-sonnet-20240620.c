
#include <stdio.h>

void createPhoneNumber(const int arr[10], char *result) {
    sprintf(result, "(%d%d%d) %d%d%d-%d%d%d%d",
            arr[0], arr[1], arr[2], arr[3], arr[4], arr[5],
            arr[6], arr[7], arr[8], arr[9]);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char phoneNumber[15];
    createPhoneNumber(numbers, phoneNumber);
    printf("%s\\n", phoneNumber);
    return 0;
}
