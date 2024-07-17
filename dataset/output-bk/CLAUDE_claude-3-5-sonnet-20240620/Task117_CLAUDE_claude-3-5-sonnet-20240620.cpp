
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <zip.h>

namespace fs = std::filesystem;

void extractZip(const std::string& zipFile, const std::string& outputDir) {
    int err;
    zip* z = zip_open(zipFile.c_str(), 0, &err);
    if (!z) {
        std::cerr << "Error opening ZIP file: " << zipFile << std::endl;
        return;
    }

    fs::create_directories(outputDir);

    int numEntries = zip_get_num_entries(z, 0);
    for (int i = 0; i < numEntries; i++) {
        struct zip_stat st;
        zip_stat_index(z, i, 0, &st);

        std::string fullPath = outputDir + "/" + st.name;
        fs::path filePath(fullPath);
        fs::create_directories(filePath.parent_path());

        zip_file* zf = zip_fopen_index(z, i, 0);
        if (!zf) {
            std::cerr << "Error opening file in ZIP: " << st.name << std::endl;
            continue;
        }

        std::ofstream outFile(fullPath, std::ios::binary);
        if (!outFile) {
            std::cerr << "Error creating output file: " << fullPath << std::endl;
            zip_fclose(zf);
            continue;
        }

        char buffer[8192];
        zip_int64_t read;
        while ((read = zip_fread(zf, buffer, sizeof(buffer))) > 0) {
            outFile.write(buffer, read);
        }

        outFile.close();
        zip_fclose(zf);
    }

    zip_close(z);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <archive_file> <output_directory>" << std::endl;
        return 1;
    }

    extractZip(argv[1], argv[2]);
    return 0;
}
