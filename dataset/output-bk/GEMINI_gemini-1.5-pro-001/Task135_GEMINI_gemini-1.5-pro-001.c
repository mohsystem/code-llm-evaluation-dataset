#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random CSRF token
void generate_csrf_token(char *token, size_t size) {
    srand((unsigned int)time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < size - 1; i++) {
        token[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    token[size - 1] = '\0';
}

int main() {
    // Generate a random CSRF token
    char csrf_token[33]; // 32 characters + null terminator
    generate_csrf_token(csrf_token, sizeof(csrf_token));

    // Print the HTML form with the CSRF token
    printf("<form method=\"POST\" action=\"/submit\">
");
    printf("  <input type=\"hidden\" name=\"csrf_token\" value=\"%s\" />
", csrf_token);
    printf("  <button type=\"submit\">Submit</button>
");
    printf("</form>
");

    return 0;
}