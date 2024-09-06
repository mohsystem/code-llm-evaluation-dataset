
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Task109_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Email validation
        String emailPattern = "^[\\\\w\\\\.-]+@[\\\\w\\\\.-]+\\\\.\\\\w+$";
        System.out.print("Enter your email: ");
        String email = scanner.nextLine();
        if (email.matches(emailPattern)) {
            System.out.println("Valid email");
        } else {
            System.out.println("Invalid email");
        }

        // Phone number validation (US format)
        String phonePattern = "^\\\\(?([0-9]{3})\\\\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$";
        System.out.print("Enter your phone number: ");
        String phone = scanner.nextLine();
        if (phone.matches(phonePattern)) {
            System.out.println("Valid phone number");
        } else {
            System.out.println("Invalid phone number");
        }

        // Password validation (at least 8 characters, 1 uppercase, 1 lowercase, 1 digit)
        String passwordPattern = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\\\d)[a-zA-Z\\\\d]{8,}$";
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();
        if (password.matches(passwordPattern)) {
            System.out.println("Valid password");
        } else {
            System.out.println("Invalid password");
        }

        scanner.close();
    }
}
