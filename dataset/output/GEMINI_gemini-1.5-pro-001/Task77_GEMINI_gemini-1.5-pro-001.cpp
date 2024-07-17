#include <iostream>
#include <fstream>
#include <string>
#include <ftp/ftp.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: ftp_download <hostname> <username> <password> <filename>" << endl;
        return 1;
    }

    string hostname = argv[1];
    string username = argv[2];
    string password = argv[3];
    string filename = argv[4];

    ftp::Client ftp;
    ftp.Connect(hostname);
    ftp.Login(username, password);
    ftp.BinaryMode();

    ofstream file(filename, ios::binary);
    if (!ftp.RetrieveFile(filename, file)) {
        cerr << "Error downloading file: " << ftp.last_response() << endl;
        return 1;
    }

    cout << "File downloaded successfully." << endl;
    return 0;
}