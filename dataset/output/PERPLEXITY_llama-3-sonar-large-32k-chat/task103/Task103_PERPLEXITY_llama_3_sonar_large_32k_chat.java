import java.util.Scanner;

public class Task103_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean passwordStrength(String password) {
        if (password.length() < 8) {
            return false;
        }
        boolean hasUpper = false, hasLower = false, hasDigit = false;
        for (char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) {
                hasUpper = true;
            } else if (Character.isLowerCase(c)) {
                hasLower = true;
            } else if (Character.isDigit(c)) {
                hasDigit = true;
            }
            if (hasUpper && hasLower && hasDigit) {
                break;
            }
        }
        return hasUpper && hasLower && hasDigit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a password: ");
        String password = scanner.nextLine();
        if (passwordStrength(password)) {
            System.out.println("Strong password");
        } else {
            System.out.println("Weak password");
        }
    }
}