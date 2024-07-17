
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zip.h>

#define BUFFER_SIZE 8192

void extract_zip(const char *zip_file, const char *output_dir) {
    int err;
    zip_t *zip = zip_open(zip_file, 0, &err);
    if (!zip) {
        fprintf(stderr, "Error opening ZIP file: %s\
", zip_file);
        return;
    }

    zip_int64_t num_entries = zip_get_num_entries(zip, 0);
    for (zip_int64_t i = 0; i < num_entries; i++) {
        const char *name = zip_get_name(zip, i, 0);
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", output_dir, name);

        zip_file_t *file = zip_fopen_index(zip, i, 0);
        if (!file) {
            fprintf(stderr, "Error opening file in ZIP: %s\
", name);
            continue;
        }

        FILE *out = fopen(full_path, "wb");
        if (!out) {
            fprintf(stderr, "Error creating output file: %s\
", full_path);
            zip_fclose(file);
            continue;
        }

        char buffer[BUFFER_SIZE];
        zip_int64_t read;
        while ((read = zip_fread(file, buffer, BUFFER_SIZE)) > 0) {
            fwrite(buffer, 1, read, out);
        }

        fclose(out);
        zip_fclose(file);
    }

    zip_close(zip);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <archive_file> <output_directory>\
", argv[0]);
        return 1;
    }

    extract_zip(argv[1], argv[2]);
    return 0;
}
