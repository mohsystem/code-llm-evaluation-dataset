#include <stdio.h>
#include <string.h>

int main() {
    char archiveFile[256], outputDir[256], command[512];

    printf("Enter the path to the archive file: ");
    fgets(archiveFile, sizeof(archiveFile), stdin);
    archiveFile[strcspn(archiveFile, "
")] = 0; 

    printf("Enter the directory to extract to (leave blank to extract to current directory): ");
    fgets(outputDir, sizeof(outputDir), stdin);
    outputDir[strcspn(outputDir, "
")] = 0;

    if (strlen(outputDir) == 0) {
        strcpy(outputDir, ".");
    }

    if (strstr(archiveFile, ".zip") != NULL) {
        sprintf(command, "unzip \"%s\" -d \"%s\"", archiveFile, outputDir); 
    } else if (strstr(archiveFile, ".tar.gz") != NULL || strstr(archiveFile, ".tgz") != NULL) {
        sprintf(command, "tar -xzf \"%s\" -C \"%s\"", archiveFile, outputDir); 
    } else if (strstr(archiveFile, ".tar") != NULL) {
        sprintf(command, "tar -xf \"%s\" -C \"%s\"", archiveFile, outputDir);
    } else {
        fprintf(stderr, "Unsupported archive format.
");
        return 1; 
    }

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Extraction failed. Error code: %d
", result);
        return 1; 
    }

    return 0; 
}