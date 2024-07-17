#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libftp.h>

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <hostname> <username> <password> <remoteFilePath>
", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *remoteFilePath = argv[4];
    char *localFilePath = strrchr(remoteFilePath, '/') + 1;

    ftp_client *client = ftp_client_create();
    if (!client) {
        printf("Unable to create FTP client.
");
        return 1;
    }

    if (ftp_connect(client, hostname, 21) != 0) {
        printf("Unable to connect to server.
");
        return 1;
    }

    if (ftp_login(client, username, password) != 0) {
        printf("Login failed.
");
        return 1;
    }

    FILE *localFile = fopen(localFilePath, "wb");
    if (!localFile) {
        printf("Unable to open local file for writing.
");
        return 1;
    }

    if (ftp_retrieve(client, remoteFilePath, localFile) != 0) {
        printf("File download failed.
");
        fclose(localFile);
        return 1;
    }

    printf("File has been downloaded successfully.
");
    fclose(localFile);

    ftp_disconnect(client);
    ftp_client_destroy(client);

    return 0;
}