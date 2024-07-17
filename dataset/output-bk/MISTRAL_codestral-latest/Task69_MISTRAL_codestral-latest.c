// C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (remove(argv[1]) == 0) {
            printf("File deleted successfully
");
        } else {
            printf("Unable to delete the file
");
        }
    } else {
        printf("Please provide a file path as an argument
");
    }
    return 0;
}