
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#elif __APPLE__
#include <cstdlib>
#else
#include <cstdlib>
#endif

void openURL(const std::string& url) {
#ifdef _WIN32
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
#elif __APPLE__
    std::string command = "open " + url;
    system(command.c_str());
#else
    std::string command = "xdg-open " + url;
    system(command.c_str());
#endif
}

int main() {
    std::cout << "Select a destination:" << std::endl;
    std::cout << "1. Google" << std::endl;
    std::cout << "2. YouTube" << std::endl;
    std::cout << "3. Wikipedia" << std::endl;
    std::cout << "4. GitHub" << std::endl;

    std::string choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    if (choice == "1") {
        openURL("https://www.google.com");
    } else if (choice == "2") {
        openURL("https://www.youtube.com");
    } else if (choice == "3") {
        openURL("https://www.wikipedia.org");
    } else if (choice == "4") {
        openURL("https://www.github.com");
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }

    return 0;
}
