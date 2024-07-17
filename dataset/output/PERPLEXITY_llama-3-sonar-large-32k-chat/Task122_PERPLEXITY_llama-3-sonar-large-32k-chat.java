import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class User {
    String username;
    String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
}

public class Main {
    static Map<String, User> users = new HashMap<>();

    public static void signup() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        users.put(username, new User(username, password));
        System.out.println("Signup successful!");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("1. Signup");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");
            String choice = scanner.nextLine();
            if (choice.equals("1")) {
                signup();
            } else if (choice.equals("2")) {
                break;
            } else {
                System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}