import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class AuthenticationSystem {
    private Map<String, String> users;

    public AuthenticationSystem() {
        this.users = new HashMap<>();
        this.users.put("admin", "password123");
        this.users.put("user", "password456");
    }

    public boolean authenticate(String username, String password) {
        return this.users.getOrDefault(username, "").equals(password);
    }

    public static void main(String[] args) {
        AuthenticationSystem auth = new AuthenticationSystem();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        if (auth.authenticate(username, password)) {
            System.out.println("Authentication successful!");
        } else {
            System.out.println("Invalid credentials!");
        }
    }
}