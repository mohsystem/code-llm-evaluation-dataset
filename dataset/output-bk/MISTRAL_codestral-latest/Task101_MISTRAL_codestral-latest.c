#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    FILE *file = fopen("script.sh", "w");
    if (file) {
        printf("File created: script.sh
");
        fclose(file);
        if (chmod("script.sh", S_IRWXU) == 0) {
            printf("File is now executable
");
        } else {
            printf("Failed to make file executable
");
        }
    } else {
        printf("Failed to create file
");
    }
    return 0;
}