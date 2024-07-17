#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validatePin(char *pin) {
    int length = strlen(pin);
    if (length != 4 && length != 6) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isdigit(pin[i])) {
            return 0;
        }
    }
    return 1;
}
int main(){
   printf("%d
", validatePin("1234"));
   printf("%d
", validatePin("12345"));
   printf("%d
", validatePin("a234"));
}