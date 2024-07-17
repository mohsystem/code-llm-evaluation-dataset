import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static HashMap<String, String> passwords = new HashMap<>();

    public static void signup(String username, String password) {
        passwords.put(username, password);
        System.out.println("Signup successful!");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Username: ");
        String username = scanner.nextLine();
        System.out.println("Enter Password: ");
        String password = scanner.nextLine();
        signup(username, password);
        scanner.close();
    }
}