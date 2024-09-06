#include <iostream>
#include <fstream>
#include <string>
#include <ftp/ftp.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: ftp_downloader <hostname> <username> <password> <remote_filename>" << std::endl;
        return 1;
    }

    std::string hostname = argv[1];
    std::string username = argv[2];
    std::string password = argv[3];
    std::string remote_filename = argv[4];

    try {
        ftp::Client ftp;
        ftp.Connect(hostname);
        ftp.Login(username, password);

        ftp.SetBinaryMode();
        ftp.RetrieveFile(remote_filename, remote_filename);

        std::cout << "File '" << remote_filename << "' downloaded successfully." << std::endl;

        ftp.Disconnect();
    } catch (const ftp::Exception& e) {
        std::cerr << "FTP error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}