// Java code
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task136_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Map<String, String> users = new HashMap<>();
        users.put("admin", "password");
        users.put("user", "password");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        if (users.containsKey(username) && users.get(username).equals(password)) {
            System.out.println("Authentication successful!");
        } else {
            System.out.println("Invalid username or password");
        }
    }
}