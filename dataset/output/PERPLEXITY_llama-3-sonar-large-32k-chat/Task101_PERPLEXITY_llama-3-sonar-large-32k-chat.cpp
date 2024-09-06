#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("script.sh");
    file << "#!/bin/bash\necho 'Hello World'" << std::endl;
    file.close();
    system("chmod +x script.sh");
    return 0;
}