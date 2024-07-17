
import java.util.Random;
import java.util.Scanner;

public class PasswordReset {
    private static final String CHAR_LOWER = "abcdefghijklmnopqrstuvwxyz";
    private static final String CHAR_UPPER = CHAR_LOWER.toUpperCase();
    private static final String NUMBER = "0123456789";
    private static final String SPECIAL_CHAR = "!@#$%&*()_+-=[]|,./?><";
    private static final String PASSWORD_ALLOW = CHAR_LOWER + CHAR_UPPER + NUMBER + SPECIAL_CHAR;

    public static String generatePassword(int length) {
        Random random = new Random();
        StringBuilder password = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            int index = random.nextInt(PASSWORD_ALLOW.length());
            password.append(PASSWORD_ALLOW.charAt(index));
        }
        return password.toString();
    }

    public static String resetPassword(String username) {
        String newPassword = generatePassword(12);
        System.out.println("Password for " + username + " has been reset.");
        System.out.println("New password: " + newPassword);
        // In a real system, you would hash and save this password
        return newPassword;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username to reset password: ");
        String username = scanner.nextLine();
        resetPassword(username);
        scanner.close();
    }
}
