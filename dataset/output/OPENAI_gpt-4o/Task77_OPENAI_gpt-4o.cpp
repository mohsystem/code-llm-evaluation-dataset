#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <libftp.h>

void downloadFile(const std::string& server, const std::string& user, const std::string& pass, const std::string& remoteFile) {
    ftp_client client;

    if (ftp_connect(&client, server.c_str(), 21) != 0) {
        std::cerr << "Unable to connect to server." << std::endl;
        return;
    }

    if (ftp_login(&client, user.c_str(), pass.c_str()) != 0) {
        std::cerr << "Login failed." << std::endl;
        return;
    }

    std::string localFile = "./" + remoteFile.substr(remoteFile.find_last_of('/') + 1);
    std::ofstream outFile(localFile, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }

    if (ftp_retrieve(&client, remoteFile.c_str(), outFile) != 0) {
        std::cerr << "File download failed." << std::endl;
    } else {
        std::cout << "File has been downloaded successfully." << std::endl;
    }

    outFile.close();
    ftp_disconnect(&client);
}

int main(int argc, char** argv) {
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <hostname> <username> <password> <remoteFilePath>" << std::endl;
        return 1;
    }

    std::string host = argv[1];
    std::string user = argv[2];
    std::string pass = argv[3];
    std::string remoteFile = argv[4];

    downloadFile(host, user, pass, remoteFile);
    return 0;
}