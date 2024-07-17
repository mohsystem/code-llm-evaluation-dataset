// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <archive.h>
#include <archive_entry.h>

#define BUF_SIZE 10240

int main(int argc, char *argv[]) {
    struct archive *a;
    struct archive_entry *entry;
    int r;
    char buff[BUF_SIZE];
    size_t size;

    a = archive_read_new();
    archive_read_support_format_all(a);
    archive_read_support_filter_all(a);
    r = archive_read_open_filename(a, "path_to_your_archive_file", 10240);
    if (r != ARCHIVE_OK) {
        fprintf(stderr, "%s
", archive_error_string(a));
        return 1;
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char *filename = archive_entry_pathname(entry);
        printf("Extracting %s
", filename);
        archive_entry_set_pathname(entry, filename);
        int fd = open(filename, O_WRONLY | O_CREAT, 0644);
        if (fd < 0) {
            perror("open");
            return 1;
        }

        while ((r = archive_read_data(a, buff, BUF_SIZE)) > 0) {
            write(fd, buff, r);
        }

        close(fd);
    }

    archive_read_close(a);
    archive_read_free(a);

    return 0;
}