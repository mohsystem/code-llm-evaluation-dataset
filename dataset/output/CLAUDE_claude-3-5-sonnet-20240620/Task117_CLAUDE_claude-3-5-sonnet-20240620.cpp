
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <zip.h>
#include <archive.h>
#include <archive_entry.h>

namespace fs = std::filesystem;

void extractZip(const std::string& zipPath, const std::string& extractPath) {
    int err = 0;
    zip* z = zip_open(zipPath.c_str(), 0, &err);
    if (z == nullptr) {
        std::cerr << "Failed to open ZIP file: " << zipPath << std::endl;
        return;
    }

    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        zip_stat_t zs;
        if (zip_stat_index(z, i, 0, &zs) == 0) {
            std::string entryName = zs.name;
            std::string fullPath = extractPath + "/" + entryName;

            if (entryName.back() == '/') {
                fs::create_directories(fullPath);
            } else {
                zip_file* zf = zip_fopen_index(z, i, 0);
                if (zf) {
                    std::ofstream outFile(fullPath, std::ios::binary);
                    char buffer[1024];
                    zip_int64_t len;
                    while ((len = zip_fread(zf, buffer, sizeof(buffer))) > 0) {
                        outFile.write(buffer, len);
                    }
                    zip_fclose(zf);
                }
            }
        }
    }

    zip_close(z);
    std::cout << "Extracted ZIP file: " << zipPath << std::endl;
}

void extractTar(const std::string& tarPath, const std::string& extractPath) {
    struct archive* a;
    struct archive_entry* entry;
    int r;

    a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);

    r = archive_read_open_filename(a, tarPath.c_str(), 10240);
    if (r != ARCHIVE_OK) {
        std::cerr << "Failed to open TAR file: " << tarPath << std::endl;
        return;
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char* currentFile = archive_entry_pathname(entry);
        std::string fullPath = extractPath + "/" + currentFile;

        if (archive_entry_filetype(entry) == AE_IFDIR) {
            fs::create_directories(fullPath);
        } else {
            std::ofstream outFile(fullPath, std::ios::binary);
            const void* buff;
            size_t size;
            int64_t offset;

            while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
                outFile.write(static_cast<const char*>(buff), size);
            }
        }
    }

    archive_read_close(a);
    archive_read_free(a);
    std::cout << "Extracted TAR file: " << tarPath << std::endl;
}

int main() {
    std::string archivePath, extractPath;

    std::cout << "Enter the path to the archive file: ";
    std::getline(std::cin, archivePath);

    std::cout << "Enter the extraction path: ";
    std::getline(std::cin, extractPath);

    fs::create_directories(extractPath);

    if (archivePath.substr(archivePath.length() - 4) == ".zip") {
        extractZip(archivePath, extractPath);
    } else if (archivePath.substr(archivePath.length() - 4) == ".tar") {
        extractTar(archivePath, extractPath);
    } else {
        std::cout << "Unsupported archive format: " << archivePath << std::endl;
    }

    return 0;
}
