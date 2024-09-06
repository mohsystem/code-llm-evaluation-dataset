import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task136_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        Map<String, String> userDatabase = new HashMap<>();
        userDatabase.put("user1", "password123");
        userDatabase.put("john_doe", "securepassword");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Username: ");
        String username = scanner.nextLine();
        System.out.print("Password: ");
        String password = scanner.nextLine();

        if (authenticate(username, password, userDatabase)) {
            System.out.println("Authentication successful. Welcome, " + username + "!");
        } else {
            System.out.println("Authentication failed. Invalid username or password.");
        }
    }

    public static boolean authenticate(String username, String password, Map<String, String> database) {
        if (database.containsKey(username) && database.get(username).equals(password)) {
            return true;
        }
        return false;
    }
}