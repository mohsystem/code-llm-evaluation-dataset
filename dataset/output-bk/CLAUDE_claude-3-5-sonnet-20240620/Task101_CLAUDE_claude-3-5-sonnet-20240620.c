
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char* fileName = "script.sh";
    FILE* file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("Error creating file.\
");
        return 1;
    }
    
    fclose(file);
    printf("File created: %s\
", fileName);
    
    if (chmod(fileName, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0) {
        printf("File permissions set to executable.\
");
    } else {
        printf("Error setting file permissions.\
");
        return 1;
    }
    
    return 0;
}
