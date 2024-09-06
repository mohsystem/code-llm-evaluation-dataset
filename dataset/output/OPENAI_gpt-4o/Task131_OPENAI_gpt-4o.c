#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data[100];
} UserData;

int main() {
    FILE *file = fopen("userData.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    UserData userData;
    fread(&userData, sizeof(UserData), 1, file);
    fclose(file);
    printf("%s\n", userData.data);
    return 0;
}