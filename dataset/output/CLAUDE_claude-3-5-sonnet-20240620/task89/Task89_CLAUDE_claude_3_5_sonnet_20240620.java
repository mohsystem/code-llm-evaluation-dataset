
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class Task89_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean checkPassword(String storedPassword, String enteredPassword) {
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

    public static void main(String[] args) {
        String storedPassword;
        try {
            storedPassword = new String(Files.readAllBytes(Paths.get("password.txt"))).trim();
        } catch (IOException e) {
            System.out.println("Password file not found.");
            return;
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String enteredPassword = scanner.nextLine();
        scanner.close();

        if (checkPassword(storedPassword, enteredPassword)) {
            System.out.println("Password correct!");
        } else {
            System.out.println("Password incorrect.");
        }
    }
}
