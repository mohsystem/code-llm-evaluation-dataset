import java.util.Scanner;

public class Task103_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a password: ");
        String password = scanner.nextLine();
        if (checkPasswordStrength(password)) {
            System.out.println("Password is strong");
        } else {
            System.out.println("Password is weak");
        }
    }

    public static boolean checkPasswordStrength(String password) {
        if (password.length() < 8) {
            return false;
        }
        if (!password.matches(".*[a-z].*")) {
            return false;
        }
        if (!password.matches(".*[A-Z].*")) {
            return false;
        }
        if (!password.matches(".*\\d.*")) {
            return false;
        }
        return true;
    }
}