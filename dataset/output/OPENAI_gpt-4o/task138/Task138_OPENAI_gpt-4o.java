import java.util.HashSet;
import java.util.Set;

class User {
    private String username;
    private Set<String> permissions;

    public User(String username) {
        this.username = username;
        this.permissions = new HashSet<>();
    }

    public void addPermission(String permission) {
        this.permissions.add(permission);
    }

    public boolean hasPermission(String permission) {
        return this.permissions.contains(permission);
    }

    public static void main(String[] args) {
        User admin = new User("admin");
        admin.addPermission("read");
        admin.addPermission("write");
        System.out.println("Admin has 'read' permission: " + admin.hasPermission("read"));
        System.out.println("Admin has 'delete' permission: " + admin.hasPermission("delete"));
    }
}