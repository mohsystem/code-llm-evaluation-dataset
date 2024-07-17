
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/rand.h>

#define MAX_SESSIONS 100
#define SESSION_ID_LENGTH 16
#define SESSION_TIMEOUT 1800 // 30 minutes in seconds

typedef struct {
    char id[SESSION_ID_LENGTH * 2 + 1];
    char username[50];
    time_t creation_time;
    time_t last_access_time;
} Session;

Session sessions[MAX_SESSIONS];
int session_count = 0;

void generate_session_id(char *id) {
    unsigned char random_bytes[SESSION_ID_LENGTH];
    RAND_bytes(random_bytes, SESSION_ID_LENGTH);
    for (int i = 0; i < SESSION_ID_LENGTH; i++) {
        sprintf(id + (i * 2), "%02x", random_bytes[i]);
    }
}

char* create_session(const char *username) {
    if (session_count >= MAX_SESSIONS) {
        return NULL;
    }

    Session *session = &sessions[session_count++];
    generate_session_id(session->id);
    strncpy(session->username, username, sizeof(session->username) - 1);
    session->creation_time = time(NULL);
    session->last_access_time = session->creation_time;

    return session->id;
}

int validate_session(const char *session_id) {
    time_t current_time = time(NULL);
    for (int i = 0; i < session_count; i++) {
        if (strcmp(sessions[i].id, session_id) == 0) {
            if (current_time - sessions[i].last_access_time <= SESSION_TIMEOUT) {
                sessions[i].last_access_time = current_time;
                return 1;
            } else {
                // Session expired, remove it
                memmove(&sessions[i], &sessions[i+1], (session_count - i - 1) * sizeof(Session));
                session_count--;
                return 0;
            }
        }
    }
    return 0;
}

void terminate_session(const char *session_id) {
    for (int i = 0; i < session_count; i++) {
        if (strcmp(sessions[i].id, session_id) == 0) {
            memmove(&sessions[i], &sessions[i+1], (session_count - i - 1) * sizeof(Session));
            session_count--;
            return;
        }
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port 8080\
");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        read(new_socket, buffer, 1024);
        char *action = strtok(buffer, " ");
        char *arg = strtok(NULL, " ");

        if (strcmp(action, "LOGIN") == 0) {
            char *session_id = create_session(arg);
            if (session_id) {
                char response[100];
                snprintf(response, sizeof(response), "Session created: %s\
", session_id);
                send(new_socket, response, strlen(response), 0);
            } else {
                send(new_socket, "Failed to create session\
", 25, 0);
            }
        } else if (strcmp(action, "VALIDATE") == 0) {
            int is_valid = validate_session(arg);
            char *response = is_valid ? "Session valid: true\
" : "Session valid: false\
";
            send(new_socket, response, strlen(response), 0);
        } else if (strcmp(action, "LOGOUT") == 0) {
            terminate_session(arg);
            send(new_socket, "Session terminated\
", 19, 0);
        } else {
            send(new_socket, "Invalid action\
", 15, 0);
        }

        close(new_socket);
    }

    return 0;
}
