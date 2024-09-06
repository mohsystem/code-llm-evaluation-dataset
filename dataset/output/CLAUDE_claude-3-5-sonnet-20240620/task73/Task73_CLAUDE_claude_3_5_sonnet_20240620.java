
import java.util.Scanner;
import java.util.regex.Pattern;

public class Task73_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean isValidAdminPassword(String password) {
        if (password.length() < 12) {
            return false;
        }
        if (!Pattern.compile("[A-Z]").matcher(password).find()) {
            return false;
        }
        if (!Pattern.compile("[a-z]").matcher(password).find()) {
            return false;
        }
        if (!Pattern.compile("\\\\d").matcher(password).find()) {
            return false;
        }
        if (!Pattern.compile("[!@#$%^&*(),.?\\":{}|<>]").matcher(password).find()) {
            return false;
        }
        if (password.toLowerCase().contains("admin")) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the admin password: ");
        String password = scanner.nextLine();
        if (isValidAdminPassword(password)) {
            System.out.println("Password is valid");
        } else {
            System.out.println("Password is invalid");
        }
        scanner.close();
    }
}
