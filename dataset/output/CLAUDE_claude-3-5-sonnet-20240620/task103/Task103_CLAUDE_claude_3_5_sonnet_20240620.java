
import java.util.Scanner;
import java.util.regex.Pattern;

public class Task103_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean checkPasswordStrength(String password) {
        if (password.length() < 8) {
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
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a password: ");
        String password = scanner.nextLine();
        if (checkPasswordStrength(password)) {
            System.out.println("Password is strong");
        } else {
            System.out.println("Password is weak");
        }
        scanner.close();
    }
}
