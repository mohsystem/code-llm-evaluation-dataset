#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
    std::ofstream file("script.sh");
    if (file.is_open()) {
        std::cout << "File created: script.sh
";
        file.close();
        if (chmod("script.sh", S_IRWXU) == 0) {
            std::cout << "File is now executable
";
        } else {
            std::cout << "Failed to make file executable
";
        }
    } else {
        std::cout << "Failed to create file
";
    }
    return 0;
}