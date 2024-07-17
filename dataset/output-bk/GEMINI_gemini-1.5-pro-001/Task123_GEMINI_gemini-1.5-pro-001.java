import java.time.LocalDateTime;
import java.util.HashMap;

class Session {
    String username;
    LocalDateTime loginTime;

    public Session(String username) {
        this.username = username;
        this.loginTime = LocalDateTime.now();
    }

    public String getSessionData() {
        return "Username: " + this.username + ", Login Time: " + this.loginTime;
    }
}

public class SessionManager {
    static HashMap<String, Session> sessions = new HashMap<>();

    public static void createSession(String username) {
        sessions.put(username, new Session(username));
        System.out.println("Session created for " + username);
    }

    public static void getSession(String username) {
        if (sessions.containsKey(username)) {
            System.out.println(sessions.get(username).getSessionData());
        } else {
            System.out.println("Session not found for " + username);
        }
    }

    public static void deleteSession(String username) {
        if (sessions.containsKey(username)) {
            sessions.remove(username);
            System.out.println("Session deleted for " + username);
        } else {
            System.out.println("Session not found for " + username);
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            System.out.print("Enter action (create/get/delete/exit): ");
            String action = scanner.nextLine();
            if (action.equals("exit")) {
                break;
            }
            System.out.print("Enter username: ");
            String username = scanner.nextLine();
            switch (action) {
                case "create":
                    createSession(username);
                    break;
                case "get":
                    getSession(username);
                    break;
                case "delete":
                    deleteSession(username);
                    break;
                default:
                    System.out.println("Invalid action");
            }
        }
    }
}