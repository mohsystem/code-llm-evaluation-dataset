#include <stdio.h>
#include <string.h>

typedef struct {
    char data[20];
} SensitiveData;

SensitiveData* createSensitiveData(char* data) {
    SensitiveData* sd = (SensitiveData*) malloc(sizeof(SensitiveData));
    strcpy(sd->data, data);
    return sd;
}

char* getData(SensitiveData* sd) {
    return sd->data;
}

int main() {
    SensitiveData* data = createSensitiveData("1234-5678-9012-3456");
    printf("%s\n", getData(data));
    free(data);
    return 0;
}