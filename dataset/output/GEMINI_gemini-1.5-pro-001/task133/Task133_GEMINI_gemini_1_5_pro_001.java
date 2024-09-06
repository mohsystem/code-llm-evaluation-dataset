import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task133_GEMINI_gemini_1_5_pro_001 {

    public static boolean isValidPassword(String password) {
        if (password.length() < 8) {
            return false;
        }
        Pattern pattern = Pattern.compile("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).+");
        Matcher matcher = pattern.matcher(password);
        return matcher.find();
    }

    public static void resetPassword() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter your new password: ");
            String newPassword = scanner.nextLine();
            System.out.print("Confirm your new password: ");
            String confirmPassword = scanner.nextLine();

            if (newPassword.equals(confirmPassword) && isValidPassword(newPassword)) {
                System.out.println("Password reset successfully!");
                break;
            } else {
                System.out.println("Invalid password or passwords don't match. Please try again.");
            }
        }
    }

    public static void main(String[] args) {
        resetPassword();
    }
}