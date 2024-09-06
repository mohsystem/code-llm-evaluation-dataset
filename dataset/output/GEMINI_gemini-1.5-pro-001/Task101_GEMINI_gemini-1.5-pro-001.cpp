#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    ofstream script("script.sh");
    script << "#!/bin/bash" << endl;
    script << "echo \"Hello from script.sh!\"" << endl;
    script.close();

    // Make the script executable
    if (system("chmod +x script.sh") != 0) {
        cerr << "Error making script executable." << endl;
        return 1;
    }

    return 0;
}