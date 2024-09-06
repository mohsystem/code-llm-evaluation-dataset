#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("script.sh", "w");
    fprintf(file, "#!/bin/bash\necho 'Hello World!\n");
    fclose(file);
    system("chmod +x script.sh");
    return 0;
}