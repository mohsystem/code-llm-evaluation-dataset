
import java.io.*;
import java.util.*;

class PermissionManager {
    private Map<String, String> users;
    private Map<String, List<String>> roles;

    public PermissionManager() {
        users = new HashMap<>();
        roles = new HashMap<>();
        roles.put("admin", Arrays.asList("read", "write", "delete", "manage_users"));
        roles.put("editor", Arrays.asList("read", "write"));
        roles.put("viewer", Arrays.asList("read"));
    }

    public void addUser(String username, String role) {
        if (!roles.containsKey(role)) {
            throw new IllegalArgumentException("Invalid role");
        }
        users.put(username, role);
    }

    public void removeUser(String username) {
        users.remove(username);
    }

    public void changeUserRole(String username, String newRole) {
        if (!users.containsKey(username)) {
            throw new IllegalArgumentException("User not found");
        }
        if (!roles.containsKey(newRole)) {
            throw new IllegalArgumentException("Invalid role");
        }
        users.put(username, newRole);
    }

    public boolean checkPermission(String username, String permission) {
        if (!users.containsKey(username)) {
            return false;
        }
        String userRole = users.get(username);
        return roles.get(userRole).contains(permission);
    }

    public void saveToFile(String filename) throws IOException {
        try (PrintWriter out = new PrintWriter(new FileWriter(filename))) {
            for (Map.Entry<String, String> entry : users.entrySet()) {
                out.println(entry.getKey() + "," + entry.getValue());
            }
        }
    }

    public void loadFromFile(String filename) throws IOException {
        users.clear();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                users.put(parts[0], parts[1]);
            }
        }
    }
}

public class Task138_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        PermissionManager pm = new PermissionManager();

        pm.addUser("alice", "admin");
        pm.addUser("bob", "editor");
        pm.addUser("charlie", "viewer");

        System.out.println(pm.checkPermission("alice", "manage_users"));  // true
        System.out.println(pm.checkPermission("bob", "write"));  // true
        System.out.println(pm.checkPermission("charlie", "delete"));  // false

        pm.changeUserRole("bob", "admin");
        System.out.println(pm.checkPermission("bob", "manage_users"));  // true

        pm.removeUser("charlie");
        System.out.println(pm.checkPermission("charlie", "read"));  // false

        try {
            pm.saveToFile("permissions.txt");
            pm.loadFromFile("permissions.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
