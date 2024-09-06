#include <fstream>
#include <iostream>
#include <sys/stat.h>

int main() {
    std::string filename = "script.sh";
    std::ofstream scriptFile(filename);
    if (scriptFile.is_open()) {
        scriptFile << "#!/bin/bash\n\necho 'Hello, World!'";
        scriptFile.close();
        chmod(filename.c_str(), S_IRWXU);
    } else {
        std::cerr << "Unable to open file";
    }
    return 0;
}