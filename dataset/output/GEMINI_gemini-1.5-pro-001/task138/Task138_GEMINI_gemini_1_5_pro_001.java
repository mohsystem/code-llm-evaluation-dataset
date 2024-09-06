import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Task138_GEMINI_gemini_1_5_pro_001 {

    static class User {
        String username;
        List<String> permissions;

        public User(String username) {
            this.username = username;
            this.permissions = new ArrayList<>();
        }

        public void addPermission(String permission) {
            if (!permissions.contains(permission)) {
                permissions.add(permission);
            }
        }

        public void removePermission(String permission) {
            permissions.remove(permission);
        }

        public boolean hasPermission(String permission) {
            return permissions.contains(permission);
        }
    }

    public static void main(String[] args) {
        Map<String, User> users = new HashMap<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter action (create user, add permission, remove permission, check permission, list users, exit): ");
            String action = scanner.nextLine();

            switch (action) {
                case "create user":
                    System.out.print("Enter username: ");
                    String username = scanner.nextLine();
                    if (users.containsKey(username)) {
                        System.out.println("User already exists.");
                    } else {
                        users.put(username, new User(username));
                        System.out.println("User created successfully.");
                    }
                    break;
                case "add permission":
                    System.out.print("Enter username: ");
                    username = scanner.nextLine();
                    if (users.containsKey(username)) {
                        System.out.print("Enter permission to add: ");
                        String permission = scanner.nextLine();
                        users.get(username).addPermission(permission);
                        System.out.println("Permission added successfully.");
                    } else {
                        System.out.println("User not found.");
                    }
                    break;
                case "remove permission":
                    System.out.print("Enter username: ");
                    username = scanner.nextLine();
                    if (users.containsKey(username)) {
                        System.out.print("Enter permission to remove: ");
                        String permission = scanner.nextLine();
                        users.get(username).removePermission(permission);
                        System.out.println("Permission removed successfully.");
                    } else {
                        System.out.println("User not found.");
                    }
                    break;
                case "check permission":
                    System.out.print("Enter username: ");
                    username = scanner.nextLine();
                    if (users.containsKey(username)) {
                        System.out.print("Enter permission to check: ");
                        String permission = scanner.nextLine();
                        if (users.get(username).hasPermission(permission)) {
                            System.out.println("User has permission.");
                        } else {
                            System.out.println("User does not have permission.");
                        }
                    } else {
                        System.out.println("User not found.");
                    }
                    break;
                case "list users":
                    if (users.isEmpty()) {
                        System.out.println("No users found.");
                    } else {
                        for (String user : users.keySet()) {
                            System.out.println(user);
                        }
                    }
                    break;
                case "exit":
                    System.exit(0);
                default:
                    System.out.println("Invalid action.");
            }
        }
    }
}