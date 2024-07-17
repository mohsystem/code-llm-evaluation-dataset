#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    int n;
    char result[MAX_LENGTH] = "";
    char str[100];
    
    printf("Enter number of strings to concatenate:
");
    scanf("%d", &n);
    getchar(); // Consume the newline

    for(int i = 0; i < n; i++) {
        printf("Enter string %d:
", i + 1);
        fgets(str, 100, stdin);
        str[strcspn(str, "
")] = '\0'; // Remove trailing newline
        strcat(result, str);
    }

    printf("Concatenated string: %s
", result);
    return 0;
}