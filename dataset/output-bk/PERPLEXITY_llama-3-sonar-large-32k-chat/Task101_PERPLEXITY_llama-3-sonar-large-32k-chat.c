#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("script.sh", "w");
    fprintf(fp, "#!/bin/bash
echo 'Hello World'
");
    fclose(fp);
    system("chmod +x script.sh");
    return 0;
}