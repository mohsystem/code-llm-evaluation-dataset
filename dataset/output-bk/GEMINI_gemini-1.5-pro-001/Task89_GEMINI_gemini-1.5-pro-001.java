import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class PasswordChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter password: ");
        String enteredPassword = scanner.nextLine();

        try (BufferedReader reader = new BufferedReader(new FileReader("password.txt"))) {
            String storedPassword = reader.readLine();

            if (storedPassword != null && comparePasswords(storedPassword, enteredPassword)) {
                System.out.println("Password matches.");
            } else {
                System.out.println("Incorrect password.");
            }

        } catch (Exception e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }

    private static boolean comparePasswords(String storedPassword, String enteredPassword) {
        if (storedPassword.length() != enteredPassword.length()) {
            return false;
        }

        for (int i = 0; i < storedPassword.length(); i++) {
            if (storedPassword.charAt(i) != enteredPassword.charAt(i)) {
                return false;
            }
        }

        return true;
    }
}