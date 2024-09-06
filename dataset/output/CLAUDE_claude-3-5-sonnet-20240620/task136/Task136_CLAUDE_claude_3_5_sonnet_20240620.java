
import java.util.HashMap;
import java.util.Scanner;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Task136_CLAUDE_claude_3_5_sonnet_20240620 {
    private static HashMap<String, String> users = new HashMap<>();
    private static Scanner scanner = new Scanner(System.in);

    public static boolean register(String username, String password) {
        if (users.containsKey(username)) {
            return false;
        }
        String hashedPassword = hashPassword(password);
        users.put(username, hashedPassword);
        return true;
    }

    public static boolean login(String username, String password) {
        if (!users.containsKey(username)) {
            return false;
        }
        String hashedPassword = hashPassword(password);
        return users.get(username).equals(hashedPassword);
    }

    private static String hashPassword(String password) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashedBytes = md.digest(password.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashedBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("1. Register\\n2. Login\\n3. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            if (choice == 1) {
                System.out.print("Enter username: ");
                String username = scanner.nextLine();
                System.out.print("Enter password: ");
                String password = scanner.nextLine();
                if (register(username, password)) {
                    System.out.println("Registration successful");
                } else {
                    System.out.println("Username already exists");
                }
            } else if (choice == 2) {
                System.out.print("Enter username: ");
                String username = scanner.nextLine();
                System.out.print("Enter password: ");
                String password = scanner.nextLine();
                if (login(username, password)) {
                    System.out.println("Login successful");
                } else {
                    System.out.println("Invalid credentials");
                }
            } else if (choice == 3) {
                break;
            } else {
                System.out.println("Invalid choice");
            }
        }
        scanner.close();
    }
}
