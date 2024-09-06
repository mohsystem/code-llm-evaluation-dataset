#include <stdio.h>
#include <sys/stat.h>

int main() {
    FILE *file = fopen("script.sh", "w");
    if (file == NULL) {
        return 1;
    }

    fputs("#!/bin/bash\n\necho 'Hello, World!'", file);
    fclose(file);

    chmod("script.sh", S_IRWXU);

    return 0;
}