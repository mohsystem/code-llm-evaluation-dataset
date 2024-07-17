#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

void unzip(const char *filename, const char *output_dir) {
    char buffer[1024];
    gzFile file = gzopen(filename, "rb");
    if(!file) {
        printf("Could not open %s
", filename);
        return;
    }
    char outpath[256];
    snprintf(outpath, sizeof(outpath), "%s/%s", output_dir, strrchr(filename, '/') + 1);
    FILE *outfile = fopen(outpath, "wb");
    if(!outfile) {
        printf("Could not open output file
");
        return;
    }
    int num_read;
    while ((num_read = gzread(file, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), num_read, outfile);
    }
    fclose(outfile);
    gzclose(file);
}

int main() {
    const char *filename = "yourfile.gz";
    const char *output_dir = "output_dir";
    unzip(filename, output_dir);
    return 0;
}