#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void retrieveFile(const char* filename) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
    send(sock, filename, strlen(filename), 0);
    char data[1024];
    int bytesRead = recv(sock, data, 1024, 0);
    if (bytesRead > 0) {
        FILE* file = fopen(filename, "wb");
        fwrite(data, 1, bytesRead, file);
        fclose(file);
        printf("File retrieved successfully
");
    } else {
        printf("File not found on the server
");
    }
    close(sock);
}

int main() {
    printf("Enter the filename: ");
    char filename[256];
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "
")] = 0; // remove newline character
    retrieveFile(filename);
    return 0;
}