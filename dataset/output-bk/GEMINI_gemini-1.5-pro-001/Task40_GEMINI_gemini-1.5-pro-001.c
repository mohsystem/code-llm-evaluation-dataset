#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <openssl/rand.h>
#include <openssl/hmac.h>

#define CSRF_TOKEN_LENGTH 32

// Function to generate a random CSRF token
char *generate_csrf_token() {
    unsigned char token[CSRF_TOKEN_LENGTH];
    if (RAND_bytes(token, sizeof(token)) != 1) {
        fprintf(stderr, "Error generating random bytes.
");
        return NULL;
    }

    // Encode the token in hexadecimal format
    char *csrf_token = malloc((CSRF_TOKEN_LENGTH * 2 + 1) * sizeof(char));
    if (csrf_token == NULL) {
        fprintf(stderr, "Memory allocation error.
");
        return NULL;
    }
    for (int i = 0; i < CSRF_TOKEN_LENGTH; i++) {
        sprintf(csrf_token + (i * 2), "%02x", token[i]);
    }
    return csrf_token;
}

// Function to verify a CSRF token
int verify_csrf_token(const char *request_token, const char *session_token) {
    if (request_token == NULL || session_token == NULL) {
        return 0; // Invalid tokens
    }

    return strcmp(request_token, session_token) == 0;
}

int main() {
    // Example usage:

    // Generate a CSRF token and store it in a session (simulated)
    char *session_token = generate_csrf_token();
    if (session_token == NULL) {
        return 1;
    }
    printf("Session Token: %s
", session_token);

    // Simulate a request with a CSRF token
    char *request_token = strdup(session_token); 

    // Verify the token
    if (verify_csrf_token(request_token, session_token)) {
        printf("CSRF token is valid.
");
    } else {
        printf("CSRF token is invalid!
");
    }

    free(session_token);
    free(request_token);

    return 0;
}