#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <archive.h>
#include <archive_entry.h>

int main() {
    const char *archiveFile = "archive.tar";
    const char *extractDir = "extracted";

    struct archive *a;
    struct archive_entry *entry;
    int r;

    a = archive_read_new();
    archive_read_support_format_all(a);
    archive_read_open_filename(a, archiveFile, 10240);

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        char filePath[256];
        strcpy(filePath, extractDir);
        strcat(filePath, "/");
        strcat(filePath, archive_entry_pathname(entry));
        mkdir(filePath, 0755);

        FILE *fp = fopen(filePath, "wb");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open file: %s
", filePath);
            return 1;
        }

        void *buf;
        la_int64_t size;
        la_int64_t offset;
        while ((r = archive_read_data_block(a, &buf, &size, &offset)) == ARCHIVE_OK) {
            fwrite(buf, 1, size, fp);
        }

        fclose(fp);
    }

    archive_read_free(a);
    return 0;
}