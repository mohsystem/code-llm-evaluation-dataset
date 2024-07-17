#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("script.sh");
    file << "#!/bin/bash
";
    file << "echo 'Hello World'
";
    file.close();
    system("chmod +x script.sh");
    return 0;
}