// C
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("script.sh", "w");
    if (fp != NULL) {
        fprintf(fp, "#!/bin/bash\necho \"Hello, World!\"");
        fclose(fp);
        system("chmod +x script.sh");
    } else {
        printf("Unable to open file");
    }
    return 0;
}