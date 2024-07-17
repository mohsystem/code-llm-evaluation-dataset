#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libftp/ftp.h>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: ftp_download <hostname> <username> <password> <filename>
");
        return 1;
    }

    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];
    char* filename = argv[4];

    ftp_session_t* session = ftp_connect(hostname);
    if (!session) {
        fprintf(stderr, "Error connecting to FTP server: %s
", ftp_error_message());
        return 1;
    }

    int ret = ftp_login(session, username, password);
    if (ret != FTP_OK) {
        fprintf(stderr, "Error logging in: %s
", ftp_error_message(session));
        ftp_close(session);
        return 1;
    }

    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing: %s
", strerror(errno));
        ftp_close(session);
        return 1;
    }

    ret = ftp_retrieve_file(session, filename, fp);
    if (ret != FTP_OK) {
        fprintf(stderr, "Error downloading file: %s
", ftp_error_message(session));
        fclose(fp);
        ftp_close(session);
        return 1;
    }

    fclose(fp);
    ftp_close(session);

    printf("File downloaded successfully.
");
    return 0;
}