#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

int main() {
    std::string url;
    std::cout << "Enter the URL of the EXE file: ";
    std::getline(std::cin, url); // Read the entire line, including spaces

    std::string filename = "downloaded_file.exe";
    HRESULT result = URLDownloadToFileA(NULL, url.c_str(), filename.c_str(), 0, NULL);

    if (result == S_OK) {
        std::cout << "File downloaded successfully.\n";

        // Execute the downloaded file
        ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
    else {
        std::cerr << "Error downloading file: " << result << std::endl;
        return 1;
    }

    return 0;
}