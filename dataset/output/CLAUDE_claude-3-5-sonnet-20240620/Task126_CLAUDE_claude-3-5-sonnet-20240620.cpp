
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::cout << "Select a destination:" << std::endl;
    std::cout << "1. Google" << std::endl;
    std::cout << "2. YouTube" << std::endl;
    std::cout << "3. Wikipedia" << std::endl;

    std::string choice;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    std::string url;
    if (choice == "1") {
        url = "https://www.google.com";
    } else if (choice == "2") {
        url = "https://www.youtube.com";
    } else if (choice == "3") {
        url = "https://www.wikipedia.org";
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
        return 1;
    }

    #ifdef _WIN32
        std::string command = "start " + url;
    #elif __APPLE__
        std::string command = "open " + url;
    #else
        std::string command = "xdg-open " + url;
    #endif

    system(command.c_str());
    return 0;
}
