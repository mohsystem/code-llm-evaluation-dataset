#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main() {
    FILE *fp = fopen("password.txt", "r");
    if(!fp) {
        perror("Failed to open file");
        return 1;
    }

    char storedPassword[MAXLEN];
    fscanf(fp, "%s", storedPassword);
    fclose(fp);

    char enteredPassword[MAXLEN];
    printf("Enter your password: ");
    scanf("%s", enteredPassword);

    int storedLen = strlen(storedPassword);
    int enteredLen = strlen(enteredPassword);
    int isMatch = storedLen == enteredLen;
    
    for(int i = 0; i < storedLen && isMatch; i++) {
        isMatch &= storedPassword[i] == enteredPassword[i];
    }

    if(isMatch) {
        printf("Password match
");
    } else {
        printf("Password does not match
");
    }

    return 0;
}