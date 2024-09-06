// Java
import java.util.HashMap;
import java.util.Scanner;

public class Task42_MISTRAL_codestral_latest {
    private static HashMap<String, String> users = new HashMap<>();

    static {
        users.put("user1", "password1");
        users.put("user2", "password2");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your username: ");
        String username = scanner.nextLine();

        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        if (users.containsKey(username) && users.get(username).equals(password)) {
            System.out.println("Authentication successful.");
        } else {
            System.out.println("Invalid username or password.");
        }

        scanner.close();
    }
}