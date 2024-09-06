// C: Sockets server to receive files
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024
#define UPLOAD_DIR "uploads/"

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};

    mkdir(UPLOAD_DIR, 0777);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_handling("bind failed");
    }

    if (listen(server_fd, 3) < 0) {
        error_handling("listen failed");
    }

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        read(new_socket, buffer, BUFSIZE);
        FILE *fp;
        char filepath[BUFSIZE] = UPLOAD_DIR;
        strcat(filepath, "uploaded_file");
        fp = fopen(filepath, "wb");
        if (fp != NULL) {
            fwrite(buffer, sizeof(char), BUFSIZE, fp);
            fclose(fp);
        }
        send(new_socket, "File successfully uploaded", strlen("File successfully uploaded"), 0);
        close(new_socket);
        memset(buffer, 0, BUFSIZE);
    }
}