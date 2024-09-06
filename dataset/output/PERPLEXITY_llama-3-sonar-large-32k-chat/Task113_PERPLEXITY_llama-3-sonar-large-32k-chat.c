#include <stdio.h>
#include <string.h>

int main() {
    int numStrings;
    printf("Enter the number of strings: ");
    scanf("%d", &numStrings);
    char result[1000] = "";
    for (int i = 0; i < numStrings; i++) {
        char temp[100];
        printf("Enter string %d: ", i + 1);
        scanf("%s", temp);
        strcat(result, temp);
        strcat(result, " ");
    }
    printf("Concatenated string: %s\n", result);
    return 0;
}