#include <iostream>
#include <fstream>
#include <zip.h>

int extractZip(const char* zipFile, const char* extractDir) {
    int err = 0;
    zip *z;
    z = zip_open(zipFile, 0, &err);
    if (err != ZIP_ER_OK) {
        std::cerr << "Error opening zip file: " << zip_file_strerror(err) << std::endl;
        return 1;
    }
    struct zip_stat st;
    zip_stat_init(&st);
    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        char fname[256];
        zip_get_name(z, i, fname, sizeof(fname), 0);
        zip_stat(z, fname, 0, &st);
        if (st.valid & ZIP_STAT_NAME) {
            std::string filePath = std::string(extractDir) + "/" + fname;
            if (st.valid & ZIP_STAT_DIR) {
                mkdir(filePath.c_str(), 0777);
            } else {
                zip_file *f = zip_fopen(z, fname, 0);
                if (!f) {
                    std::cerr << "Error opening file in zip: " << fname << std::endl;
                    return 1;
                }
                std::ofstream fileOut(filePath, std::ios::binary);
                char buffer[1024];
                zip_int64_t len;
                while ((len = zip_fread(f, buffer, 1024)) > 0) {
                    fileOut.write(buffer, len);
                }
                zip_fclose(f);
                fileOut.close();
            }
        }
    }
    zip_close(z);
    return 0;
}

int main() {
    extractZip("example.zip", "extracted_zip");
    return 0;
}