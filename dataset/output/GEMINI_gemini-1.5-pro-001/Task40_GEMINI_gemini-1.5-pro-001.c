// CSRF protection typically involves server-side frameworks
// and isn't easily implemented in pure C without external libraries.
// This code focuses on the form structure and user input handling.

#include <stdio.h>
#include <string.h>

int main() {
    char username[100];

    printf("<html><body>");
    printf("<form method='post'>");
    // CSRF protection mechanisms would be added here
    printf("<label for='username'>Username:</label>");
    printf("<input type='text' id='username' name='username' />");
    printf("<button type='submit'>Update Settings</button>");
    printf("</form>");
    printf("</body></html>");

    // Simulated form submission handling
    fgets(username, sizeof(username), stdin); // Assuming input is sent via POST
    username[strcspn(username, "\r\n")] = 0; // Remove potential newline
    printf("Username to update: %s\n", username);

    return 0;
}