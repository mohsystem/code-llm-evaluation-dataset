// C (using miniz for ZIP files)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniz.h"

void extractZip(const char* zipFilePath, const char* destDir) {
    mz_zip_archive zipArchive = {0};
    if (!mz_zip_reader_init_file(&zipArchive, zipFilePath)) {
        printf("Error opening archive\n");
        return;
    }

    mz_uint numFiles = mz_zip_reader_get_num_files(&zipArchive);
    for (mz_uint i = 0; i < numFiles; ++i) {
        mz_zip_archive_file_stat fileStat;
        if (!mz_zip_reader_file_stat(&zipArchive, i, &fileStat)) {
            printf("Error reading file stat\n");
            mz_zip_reader_end(&zipArchive);
            return;
        }

        char filePath[256];
        snprintf(filePath, sizeof(filePath), "%s/%s", destDir, fileStat.m_filename);

        if (mz_zip_reader_is_file_a_directory(&zipArchive, i)) {
            mkdir(filePath, 0755);
        } else {
            FILE* extractedFile = fopen(filePath, "wb");
            if (!extractedFile) {
                printf("Error creating file\n");
                mz_zip_reader_end(&zipArchive);
                return;
            }

            if (!mz_zip_reader_extract_to_file(&zipArchive, i, filePath, 0)) {
                printf("Error extracting file\n");
                fclose(extractedFile);
                mz_zip_reader_end(&zipArchive);
                return;
            }

            fclose(extractedFile);
        }
    }

    mz_zip_reader_end(&zipArchive);
}

int main() {
    extractZip("path/to/archive.zip", "path/to/destination");
    return 0;
}