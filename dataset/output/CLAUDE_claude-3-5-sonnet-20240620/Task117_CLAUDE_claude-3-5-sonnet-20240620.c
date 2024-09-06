
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <zip.h>
#include <archive.h>
#include <archive_entry.h>

#define MAX_PATH 1024

void create_directory(const char* path) {
    #ifdef _WIN32
    _mkdir(path);
    #else
    mkdir(path, 0777);
    #endif
}

void extract_zip(const char* zip_path, const char* extract_path) {
    int err = 0;
    zip* z = zip_open(zip_path, 0, &err);
    if (z == NULL) {
        fprintf(stderr, "Failed to open ZIP file: %s\\n", zip_path);
        return;
    }

    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        struct zip_stat zs;
        if (zip_stat_index(z, i, 0, &zs) == 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", extract_path, zs.name);

            if (zs.name[strlen(zs.name) - 1] == '/') {
                create_directory(full_path);
            } else {
                zip_file* zf = zip_fopen_index(z, i, 0);
                if (zf) {
                    FILE* outfile = fopen(full_path, "wb");
                    if (outfile) {
                        char buffer[1024];
                        zip_int64_t len;
                        while ((len = zip_fread(zf, buffer, sizeof(buffer))) > 0) {
                            fwrite(buffer, 1, len, outfile);
                        }
                        fclose(outfile);
                    }
                    zip_fclose(zf);
                }
            }
        }
    }

    zip_close(z);
    printf("Extracted ZIP file: %s\\n", zip_path);
}

void extract_tar(const char* tar_path, const char* extract_path) {
    struct archive* a;
    struct archive_entry* entry;
    int r;

    a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);

    r = archive_read_open_filename(a, tar_path, 10240);
    if (r != ARCHIVE_OK) {
        fprintf(stderr, "Failed to open TAR file: %s\\n", tar_path);
        return;
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char* current_file = archive_entry_pathname(entry);
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", extract_path, current_file);

        if (archive_entry_filetype(entry) == AE_IFDIR) {
            create_directory(full_path);
        } else {
            FILE* outfile = fopen(full_path, "wb");
            if (outfile) {
                const void* buff;
                size_t size;
                int64_t offset;

                while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
                    fwrite(buff, 1, size, outfile);
                }
                fclose(outfile);
            }
        }
    }

    archive_read_close(a);
    archive_read_free(a);
    printf("Extracted TAR file: %s\\n", tar_path);
}

int main() {
    char archive_path[MAX_PATH];
    char extract_path[MAX_PATH];

    printf("Enter the path to the archive file: ");
    fgets(archive_path, sizeof(archive_path), stdin);
    archive_path[strcspn(archive_path, "\\n")] = 0;

    printf("Enter the extraction path: ");
    fgets(extract_path, sizeof(extract_path), stdin);
    extract_path[strcspn(extract_path, "\\n")] = 0;

    create_directory(extract_path);

    size_t len = strlen(archive_path);
    if (len > 4 && strcmp(archive_path + len - 4, ".zip") == 0) {
        extract_zip(archive_path, extract_path);
    } else if (len > 4 && strcmp(archive_path + len - 4, ".tar") == 0) {
        extract_tar(archive_path, extract_path);
    } else {
        printf("Unsupported archive format: %s\\n", archive_path);
    }

    return 0;
}
