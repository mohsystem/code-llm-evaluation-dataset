import java.util.Scanner;

public class Authentication {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get user credentials
        System.out.print("Username: ");
        String username = scanner.nextLine();
        System.out.print("Password: ");
        String password = scanner.nextLine();

        // Authenticate user
        if (authenticate(username, password)) {
            System.out.println("Authentication successful. Welcome!");
        } else {
            System.out.println("Authentication failed. Invalid username or password.");
        }
    }

    public static boolean authenticate(String username, String password) {
        // Check if the provided username and password match a predefined set
        String validUsername = "user";
        String validPassword = "password";
        return username.equals(validUsername) && password.equals(validPassword);
    }
}