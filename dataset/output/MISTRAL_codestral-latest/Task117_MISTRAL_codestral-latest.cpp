// C++ (using libarchive for various archive formats)
#include <archive.h>
#include <archive_entry.h>
#include <iostream>
#include <string>

void extractArchive(const std::string& filePath, const std::string& destDir) {
    struct archive* a = archive_read_new();
    struct archive* ext = archive_write_disk_new();
    archive_write_disk_set_options(ext, ARCHIVE_EXTRACT_TIME);
    archive_read_support_format_all(a);
    archive_read_support_filter_all(a);

    if (archive_read_open_filename(a, filePath.c_str(), 10240) != ARCHIVE_OK) {
        std::cerr << "Error opening archive: " << archive_error_string(a) << std::endl;
        return;
    }

    struct archive_entry* entry;
    int r;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::string path = destDir + "/" + std::string(archive_entry_pathname(entry));
        archive_entry_set_pathname(entry, path.c_str());
        r = archive_write_header(ext, entry);
        if (r != ARCHIVE_OK) {
            std::cerr << "Error writing header: " << archive_error_string(ext) << std::endl;
            return;
        }
        if (!archive_entry_size_is_set(entry) || archive_entry_size(entry) > 0) {
            const void* buff;
            size_t size;
            int64_t offset;
            while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
                r = archive_write_data_block(ext, buff, size, offset);
                if (r != ARCHIVE_OK) {
                    std::cerr << "Error writing data: " << archive_error_string(ext) << std::endl;
                    return;
                }
            }
        }
        r = archive_write_finish_entry(ext);
        if (r != ARCHIVE_OK) {
            std::cerr << "Error finishing entry: " << archive_error_string(ext) << std::endl;
            return;
        }
    }

    archive_read_close(a);
    archive_read_free(a);
    archive_write_close(ext);
    archive_write_free(ext);
}

int main() {
    extractArchive("path/to/archive.zip", "path/to/destination");
    return 0;
}