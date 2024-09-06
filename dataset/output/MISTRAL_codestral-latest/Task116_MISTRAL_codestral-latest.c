// C does not have built-in support for changing user passwords or dropping privileges.
// This is a simplified example of how you might use the system() function to run a shell command.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[50], newPassword[50], command[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", newPassword);

    sprintf(command, "echo '%s:%s' | sudo chpasswd", username, newPassword);
    int result = system(command);

    // Dropping privileges is not directly supported in C.
    // You would need to use a native function like setuid() or seteuid() for this.

    return 0;
}