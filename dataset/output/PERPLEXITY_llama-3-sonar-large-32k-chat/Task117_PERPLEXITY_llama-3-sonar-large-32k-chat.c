// C does not have a built-in library for extracting zip files. You can use a third-party library like libzip.
// Here is an example using libzip:
#include <zip.h>
#include <zipconf.h>

int extractZip(const char* zipFile, const char* extractDir) {
    int err = 0;
    zip *z;
    z = zip_open(zipFile, 0, &err);
    if (err != ZIP_ER_OK) {
        fprintf(stderr, "Error opening zip file: %s\n", zip_file_strerror(err));
        return 1;
    }
    struct zip_stat st;
    zip_stat_init(&st);
    for (int i = 0; i < zip_get_num_entries(z, 0); i++) {
        char fname[256];
        zip_get_name(z, i, fname, sizeof(fname), 0);
        zip_stat(z, fname, 0, &st);
        if (st.valid & ZIP_STAT_NAME) {
            char filePath[256];
            sprintf(filePath, "%s/%s", extractDir, fname);
            if (st.valid & ZIP_STAT_DIR) {
                mkdir(filePath, 0777);
            } else {
                zip_file *f = zip_fopen(z, fname, 0);
                if (!f) {
                    fprintf(stderr, "Error opening file in zip: %s\n", fname);
                    return 1;
                }
                FILE *fileOut = fopen(filePath, "wb");
                char buffer[1024];
                zip_int64_t len;
                while ((len = zip_fread(f, buffer, 1024)) > 0) {
                    fwrite(buffer, 1, len, fileOut);
                }
                zip_fclose(f);
                fclose(fileOut);
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