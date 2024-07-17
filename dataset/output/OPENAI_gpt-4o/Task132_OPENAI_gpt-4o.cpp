#include <iostream>
#include <fstream>
#include <ctime>

void logEvent(const std::string& event) {
    std::ofstream logfile("security.log", std::ios_base::app);
    if (logfile.is_open()) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        logfile << 1900 + ltm->tm_year << "/"
                << 1 + ltm->tm_mon << "/"
                << ltm->tm_mday << " "
                << 1 + ltm->tm_hour << ":"
                << 1 + ltm->tm_min << ":"
                << 1 + ltm->tm_sec << " - "
                << event << std::endl;
    }
}

int main() {
    logEvent("User login detected.");
    logEvent("Unauthorized access attempt detected.");
    logEvent("File integrity check failed.");
    return 0;
}