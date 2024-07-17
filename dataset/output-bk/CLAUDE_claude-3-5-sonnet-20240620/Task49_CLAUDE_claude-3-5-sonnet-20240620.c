
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sqlite3.h>

#define PORT 8000
#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    recv(client_socket, buffer, sizeof(buffer), 0);

    char method[10], path[100], query[100];
    sscanf(buffer, "%s %[^?]?%s", method, path, query);

    if (strcmp(method, "POST") == 0 && strcmp(path, "/api/user") == 0) {
        char name[50], email[50];
        sscanf(query, "name=%[^&]&email=%s", name, email);

        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open("users.db", &db);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Cannot open database: %s\
", sqlite3_errmsg(db));
            sqlite3_close(db);
            return;
        }

        char *sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT);"
                    "INSERT INTO users (name, email) VALUES (?, ?);";

        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Failed to prepare statement: %s\
", sqlite3_errmsg(db));
            sqlite3_close(db);
            return;
        }

        sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, email, -1, SQLITE_STATIC);

        rc = sqlite3_step(stmt);

        if (rc != SQLITE_DONE) {
            fprintf(stderr, "Execution failed: %s\
", sqlite3_errmsg(db));
        } else {
            char *response = "HTTP/1.1 200 OK\\r\
Content-Type: text/plain\\r\
\\r\
User data stored successfully";
            send(client_socket, response, strlen(response), 0);
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);
    } else {
        char *response = "HTTP/1.1 405 Method Not Allowed\\r\
Content-Type: text/plain\\r\
\\r\
Method not allowed";
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);
    printf("Server listening on port %d\
", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        handle_request(client_socket);
    }

    return 0;
}
