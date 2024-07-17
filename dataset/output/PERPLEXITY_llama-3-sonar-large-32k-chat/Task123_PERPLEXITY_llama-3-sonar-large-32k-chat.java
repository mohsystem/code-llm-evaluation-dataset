import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class UserSession {
    private String username;
    private boolean loggedIn;

    public UserSession(String username) {
        this.username = username;
        this.loggedIn = false;
    }

    public void login() {
        this.loggedIn = true;
        System.out.println(username + " has logged in.");
    }

    public void logout() {
        this.loggedIn = false;
        System.out.println(username + " has logged out.");
    }
}

public class Main {
    public static void main(String[] args) {
        Map<String, UserSession> sessions = new HashMap<>();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("1. Create session");
            System.out.println("2. Login");
            System.out.println("3. Logout");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline left-over
            if (choice == 1) {
                System.out.print("Enter username: ");
                String username = scanner.nextLine();
                sessions.put(username, new UserSession(username));
                System.out.println("Session created for " + username + ".");
            } else if (choice == 2) {
                System.out.print("Enter username: ");
                String username = scanner.nextLine();
                if (sessions.containsKey(username)) {
                    sessions.get(username).login();
                } else {
                    System.out.println("Session not found.");
                }
            } else if (choice == 3) {
                System.out.print("Enter username: ");
                String username = scanner.nextLine();
                if (sessions.containsKey(username)) {
                    sessions.get(username).logout();
                } else {
                    System.out.println("Session not found.");
                }
            } else if (choice == 4) {
                break;
            } else {
                System.out.println("Invalid option. Please try again.");
            }
        }
    }
}