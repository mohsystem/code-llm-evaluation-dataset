#include <iostream>
#include <cstdlib>
#include <csignal>
using namespace std;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <PID>" << endl;
        return 1;
    }
    int pid = atoi(argv[1]);
    if (kill(pid, SIGTERM) == -1) {
        perror("Error terminating process");
        return 1;
    }
    cout << "Process with PID " << pid << " terminated successfully." << endl;
    return 0;
}