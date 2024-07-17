import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class UserRegistrationSystem {
    private static Map<String, String> database = new HashMap<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the User Registration System!");
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.print("Enter your email: ");
        String email = scanner.nextLine();
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        registerUser(name, email, password);

        System.out.println("User registered successfully!");
    }

    private static void registerUser(String name, String email, String password) {
        database.put(email, name + ":" + password);
        System.out.println("User information stored in database:");
        System.out.println("Email: " + email);
        System.out.println("Name: " + name);
        System.out.println("Password: " + password);
    }
}