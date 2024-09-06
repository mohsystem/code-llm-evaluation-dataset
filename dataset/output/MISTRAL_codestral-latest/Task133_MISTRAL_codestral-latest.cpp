// C++ code for password reset functionality

#include <iostream>
#include <string>

std::string resetPassword(std::string currentPassword, std::string newPassword, std::string confirmPassword) {
    // For simplicity, let's assume the current password is "oldpassword"
    if (currentPassword != "oldpassword") {
        return "Current password is incorrect.";
    } else if (newPassword != confirmPassword) {
        return "New password and confirm password do not match.";
    } else {
        // In a real-world application, you would update the password here
        return "Password reset successful.";
    }
}

int main() {
    // Test the function
    std::cout << resetPassword("oldpassword", "newpassword", "newpassword") << std::endl;
    return 0;
}