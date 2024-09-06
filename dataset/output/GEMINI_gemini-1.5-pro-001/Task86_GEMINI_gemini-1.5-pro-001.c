#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

int main() {
    char url[256];
    printf("Enter the URL of the EXE file: ");
    fgets(url, sizeof(url), stdin); // Read the entire line, including spaces
    url[strcspn(url, "\n")] = 0; // Remove trailing newline

    char filename[] = "downloaded_file.exe";
    HRESULT result = URLDownloadToFileA(NULL, url, filename, 0, NULL);

    if (result == S_OK) {
        printf("File downloaded successfully.\n");

        // Execute the downloaded file
        ShellExecuteA(NULL, "open", filename, NULL, NULL, SW_SHOWNORMAL);
    } else {
        fprintf(stderr, "Error downloading file: %lu\n", result);
        return 1;
    }

    return 0;
}