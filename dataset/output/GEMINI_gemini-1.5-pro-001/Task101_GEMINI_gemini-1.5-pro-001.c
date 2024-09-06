#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *script = fopen("script.sh", "w");
    if (script == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(script, "#!/bin/bash\n");
    fprintf(script, "echo \"Hello from script.sh!\"\n");
    fclose(script);

    if (system("chmod +x script.sh") != 0) {
        perror("Error making script executable");
        return 1;
    }

    return 0;
}