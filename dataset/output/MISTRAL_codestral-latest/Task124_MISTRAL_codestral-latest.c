// C
#include <stdio.h>
#include <conio.h>

int main() {
    char password[30];
    int i = 0;
    char a;

    printf("Enter password: ");
    while (1) {
        a = _getch();
        if (a == '\r') {
            password[i] = '\0';
            break;
        } else if (a == '\b') {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i] = a;
            i++;
            printf("*");
        }
    }
    return 0;
}