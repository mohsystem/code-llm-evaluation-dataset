#include <stdio.h>
#include <stdlib.h>

int main() {
    char url[256];
    printf("Enter a URL: ");
    scanf("%s", url);

    char command[512];
    snprintf(command, sizeof(command), "curl -s \"%s\"", url);

    FILE *fp;
    char path[1035];

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command
" );
        exit(1);
    }

    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);
    return 0;
}