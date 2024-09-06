#include <iostream>
#include <cstdlib>
#include <string>
#include <signal.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <PID>" << endl;
        return 1;
    }

    int pid = stoi(argv[1]);

    if (kill(pid, SIGKILL) == 0) {
        cout << "Process with PID " << pid << " has been terminated." << endl;
    } else {
        cerr << "Error terminating process with PID " << pid << endl;
        return 1;
    }

    return 0;
}