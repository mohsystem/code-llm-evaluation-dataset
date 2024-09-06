
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

int main() {
    const char* filename = "script.sh";
    const char* content = "#!/bin/bash\\necho \\"Hello, World!\\"";

    // Create the file
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        std::cout << "File created successfully." << std::endl;
    } else {
        std::cerr << "Unable to create file." << std::endl;
        return 1;
    }

    // Make it executable
    if (chmod(filename, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == 0) {
        std::cout << "File made executable successfully." << std::endl;
    } else {
        std::cerr << "Unable to change file permissions." << std::endl;
        return 1;
    }

    return 0;
}
