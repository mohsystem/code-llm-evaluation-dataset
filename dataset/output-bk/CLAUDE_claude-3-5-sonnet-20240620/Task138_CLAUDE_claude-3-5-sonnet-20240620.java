
import java.io.*;
import java.util.*;

class User {
    String username;
    String role;
    List<String> permissions;

    User(String username, String role) {
        this.username = username;
        this.role = role;
        this.permissions = new ArrayList<>();
    }
}

class PermissionManager {
    private Map<String, User> users;
    private Map<String, List<String>> roles;

    PermissionManager() {
        users = new HashMap<>();
        roles = new HashMap<>();
        roles.put("admin", Arrays.asList("read", "write", "delete", "manage_users"));
        roles.put("editor", Arrays.asList("read", "write"));
        roles.put("viewer", Collections.singletonList("read"));
    }

    void addUser(String username, String role) {
        if (!roles.containsKey(role)) {
            throw new IllegalArgumentException("Invalid role");
        }
        User user = new User(username, role);
        user.permissions = roles.get(role);
        users.put(username, user);
    }

    void removeUser(String username) {
        users.remove(username);
    }

    void changeUserRole(String username, String newRole) {
        if (users.containsKey(username) && roles.containsKey(newRole)) {
            User user = users.get(username);
            user.role = newRole;
            user.permissions = roles.get(newRole);
        }
    }

    boolean checkPermission(String username, String permission) {
        if (users.containsKey(username)) {
            return users.get(username).permissions.contains(permission);
        }
        return false;
    }

    void saveToFile(String filename) throws IOException {
        try (PrintWriter out = new PrintWriter(new FileWriter(filename))) {
            for (User user : users.values()) {
                out.printf("%s,%s,%s%n", user.username, user.role, String.join(":", user.permissions));
            }
        }
    }

    void loadFromFile(String filename) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                addUser(parts[0], parts[1]);
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        PermissionManager pm = new PermissionManager();

        pm.addUser("alice", "admin");
        pm.addUser("bob", "editor");
        pm.addUser("charlie", "viewer");

        System.out.println(pm.checkPermission("alice", "manage_users")); // true
        System.out.println(pm.checkPermission("bob", "write")); // true
        System.out.println(pm.checkPermission("charlie", "delete")); // false

        pm.changeUserRole("bob", "admin");
        System.out.println(pm.checkPermission("bob", "manage_users")); // true

        pm.removeUser("charlie");
        System.out.println(pm.checkPermission("charlie", "read")); // false

        try {
            pm.saveToFile("permissions.txt");
            PermissionManager newPm = new PermissionManager();
            newPm.loadFromFile("permissions.txt");
            System.out.println(newPm.checkPermission("alice", "manage_users")); // true
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
