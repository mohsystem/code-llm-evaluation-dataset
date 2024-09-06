import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Task89_GEMINI_gemini_1_5_pro_001 {

    public static boolean checkPassword(String storedPassword) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter password: ");
        String enteredPassword = scanner.nextLine();
        if (enteredPassword.length() != storedPassword.length()) {
            return false;
        }
        for (int i = 0; i < storedPassword.length(); i++) {
            if (storedPassword.charAt(i) != enteredPassword.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("password.txt"))) {
            String storedPassword = reader.readLine();
            if (checkPassword(storedPassword)) {
                System.out.println("Passwords match.");
            } else {
                System.out.println("Passwords do not match.");
            }
        } catch (IOException e) {
            System.out.println("Password file not found. Please create 'password.txt'.");
        }
    }
}