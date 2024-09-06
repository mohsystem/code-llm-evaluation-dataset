
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char* filename = "script.sh";
    const char* content = "#!/bin/bash\\necho \\"Hello, World!\\"";

    // Create the file
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fputs(content, file);
        fclose(file);
        printf("File created successfully.\\n");
    } else {
        fprintf(stderr, "Unable to create file.\\n");
        return 1;
    }

    // Make it executable
    if (chmod(filename, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0) {
        printf("File made executable successfully.\\n");
    } else {
        fprintf(stderr, "Unable to change file permissions.\\n");
        return 1;
    }

    return 0;
}
