#include <iostream>
#include <fstream>
#include <string>
#include <archive.h>
#include <archive_entry.h>

int main() {
    const std::string archiveFile = "archive.tar";
    const std::string extractDir = "extracted";

    struct archive *a;
    struct archive_entry *entry;
    int r;

    a = archive_read_new();
    archive_read_support_format_all(a);
    archive_read_open_filename(a, archiveFile.c_str(), 10240);

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::string filePath = extractDir + "/" + std::string(archive_entry_pathname(entry));
        mkdir(filePath.c_str(), 0755);

        std::ofstream fp(filePath, std::ios::binary);
        if (!fp) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return 1;
        }

        void *buf;
        la_int64_t size;
        la_int64_t offset;
        while ((r = archive_read_data_block(a, &buf, &size, &offset)) == ARCHIVE_OK) {
            fp.write(static_cast<char*>(buf), size);
        }

        fp.close();
    }

    archive_read_free(a);
    return 0;
}