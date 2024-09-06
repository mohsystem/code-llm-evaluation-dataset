#include <stdio.h>
#include <string.h>

int main() {
    int num_strings;
    char concatenated_string[1000] = ""; // Assuming a maximum concatenated string length

    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);
    getchar(); // Consume newline character

    for (int i = 0; i < num_strings; i++) {
        char user_string[100]; // Assuming a maximum user string length
        printf("Enter string %d: ", i + 1);
        fgets(user_string, sizeof(user_string), stdin);
        user_string[strcspn(user_string, "\n")] = 0; // Remove potential newline
        strcat(concatenated_string, user_string);
    }
    printf("Concatenated string: %s\n", concatenated_string);
    return 0;
}