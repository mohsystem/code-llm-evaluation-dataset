
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

int main() {
    const char* fileName = "script.sh";
    std::ofstream file(fileName);
    
    if (file.is_open()) {
        file.close();
        std::cout << "File created: " << fileName << std::endl;
    } else {
        std::cout << "Error creating file." << std::endl;
        return 1;
    }
    
    if (chmod(fileName, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0) {
        std::cout << "File permissions set to executable." << std::endl;
    } else {
        std::cout << "Error setting file permissions." << std::endl;
        return 1;
    }
    
    return 0;
}
