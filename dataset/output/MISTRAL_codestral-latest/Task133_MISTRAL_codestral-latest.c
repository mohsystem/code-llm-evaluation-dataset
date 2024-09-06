// C code for password reset functionality

#include <stdio.h>
#include <string.h>

const char* resetPassword(const char* currentPassword, const char* newPassword, const char* confirmPassword) {
    // For simplicity, let's assume the current password is "oldpassword"
    if (strcmp(currentPassword, "oldpassword") != 0) {
        return "Current password is incorrect.";
    } else if (strcmp(newPassword, confirmPassword) != 0) {
        return "New password and confirm password do not match.";
    } else {
        // In a real-world application, you would update the password here
        return "Password reset successful.";
    }
}

int main() {
    // Test the function
    printf("%s\n", resetPassword("oldpassword", "newpassword", "newpassword"));
    return 0;
}