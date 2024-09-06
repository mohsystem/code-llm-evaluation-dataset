#include <iostream>
#include <fstream>
#include <vector>
#include <zip.h>
#include <archive.h>
#include <archive_entry.h>

void extract_zip(const std::string &file_path, const std::string &extract_to) {
    int err = 0;
    zip_t *archive = zip_open(file_path.c_str(), 0, &err);
    if (!archive) {
        std::cerr << "Failed to open ZIP archive\n";
        return;
    }

    zip_int64_t entries = zip_get_num_entries(archive, 0);
    for (zip_int64_t i = 0; i < entries; ++i) {
        struct zip_stat st;
        zip_stat_index(archive, i, 0, &st);

        std::string full_path = extract_to + "/" + st.name;
        std::ofstream out_file(full_path, std::ios::binary);
        struct zip_file *file = zip_fopen_index(archive, i, 0);
        char buffer[8192];
        zip_int64_t bytes_read;

        while ((bytes_read = zip_fread(file, buffer, sizeof(buffer))) > 0)
            out_file.write(buffer, bytes_read);

        zip_fclose(file);
        out_file.close();
    }
    zip_close(archive);
}

void extract_tar(const std::string &file_path, const std::string &extract_to) {
    struct archive *a = archive_read_new();
    struct archive_entry *entry;

    archive_read_support_format_tar(a);
    int r = archive_read_open_filename(a, file_path.c_str(), 10240);
    if (r != ARCHIVE_OK) {
        std::cerr << "Failed to open TAR archive\n";
        return;
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::string full_path = extract_to + "/" + archive_entry_pathname(entry);
        std::ofstream out_file(full_path, std::ios::binary);

        const void *buff;
        size_t size;
        int64_t offset;

        while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
            out_file.write(static_cast<const char *>(buff), size);
        }
        out_file.close();
    }
    archive_read_free(a);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <archive_path> <extract_to>\n";
        return 1;
    }

    std::string archive_path = argv[1];
    std::string extract_to = argv[2];

    if (archive_path.ends_with(".zip")) {
        extract_zip(archive_path, extract_to);
    } else if (archive_path.ends_with(".tar")) {
        extract_tar(archive_path, extract_to);
    } else {
        std::cerr << "Unsupported file type\n";
    }

    return 0;
}