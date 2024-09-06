// Java code for password reset functionality

public class Task133_MISTRAL_codestral_latest {
    public static String resetPassword(String currentPassword, String newPassword, String confirmPassword) {
        // For simplicity, let's assume the current password is "oldpassword"
        if (!currentPassword.equals("oldpassword")) {
            return "Current password is incorrect.";
        } else if (!newPassword.equals(confirmPassword)) {
            return "New password and confirm password do not match.";
        } else {
            // In a real-world application, you would update the password here
            return "Password reset successful.";
        }
    }

    public static void main(String[] args) {
        // Test the function
        System.out.println(resetPassword("oldpassword", "newpassword", "newpassword"));
    }
}