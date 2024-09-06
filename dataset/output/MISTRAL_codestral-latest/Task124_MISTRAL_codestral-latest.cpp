// C++
#include <iostream>
#include <conio.h>

int main() {
    char password[30];
    int i = 0;
    char a;

    std::cout << "Enter password: ";
    while (1) {
        a = _getch();
        if (a == '\r') {
            password[i] = '\0';
            break;
        } else if (a == '\b') {
            if (i > 0) {
                i--;
                std::cout << "\b \b";
            }
        } else {
            password[i] = a;
            i++;
            std::cout << "*";
        }
    }
    return 0;
}