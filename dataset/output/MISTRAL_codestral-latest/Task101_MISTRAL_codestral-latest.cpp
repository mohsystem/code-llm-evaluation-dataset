// C++
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    std::ofstream outfile("script.sh");
    if (outfile.is_open()) {
        outfile << "#!/bin/bash\necho \"Hello, World!\"";
        outfile.close();
        std::system("chmod +x script.sh");
    } else {
        std::cout << "Unable to open file";
    }
    return 0;
}