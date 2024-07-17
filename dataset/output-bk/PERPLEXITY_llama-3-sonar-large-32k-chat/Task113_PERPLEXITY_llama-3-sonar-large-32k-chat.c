#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of strings:
");
    scanf("%d", &n);
    char result[1000] = "";
    for (int i = 0; i < n; i++) {
        printf("Enter string %d:
", i + 1);
        char str[100];
        scanf("%s", str);
        strcat(result, str);
    }
    printf("Concatenated string: %s
", result);
    return 0;
}