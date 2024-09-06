code here:
// C++ does not have a built-in way to open a web browser, so we'll use the system() function
#include <iostream>
#include <string>

void openWebpage(const std::string& url) {
    std::string command = "start " + url; // for Windows
    // std::string command = "open " + url; // for macOS
    // std::string command = "xdg-open " + url; // for Linux
    system(command.c_str());
}

int main() {
    std::cout << "Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'youtube' to go to YouTube: ";
    std::string user_input;
    std::cin >> user_input;
    if (user_input == "google") {
        openWebpage("https://www.google.com");
    } else if (user_input == "facebook") {
        openWebpage("https://www.facebook.com");
    } else if (user_input == "youtube") {
        openWebpage("https://www.youtube.com");
    } else {
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    return 0;
}