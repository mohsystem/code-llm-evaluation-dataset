#include <iostream>
#include <fstream>
#include <filesystem>
#include <archive.h>
#include <archive_entry.h>

void extract(const char *filename, const char *output_dir) {
    struct archive *a;
    struct archive *ext;
    struct archive_entry *entry;
    int flags = ARCHIVE_EXTRACT_TIME;
    a = archive_read_new();
    ext = archive_write_disk_new();
    archive_read_support_format_zip(a);
    archive_read_open_filename(a, filename, 10240);
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::filesystem::create_directories(output_dir);
        std::filesystem::path outpath = std::filesystem::path(output_dir) / archive_entry_pathname(entry);
        archive_entry_set_pathname(entry, outpath.c_str());
        archive_write_header(ext, entry);
        const void *buff;
        size_t size;
        la_int64_t offset;
        while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
            archive_write_data_block(ext, buff, size, offset);
        }
        archive_write_finish_entry(ext);
    }
    archive_read_close(a);
    archive_write_close(ext);
    archive_read_free(a);
    archive_write_free(ext);
}

int main() {
    const char *filename = "yourfile.tar";
    const char *output_dir = "output_dir";
    extract(filename, output_dir);
    return 0;
}