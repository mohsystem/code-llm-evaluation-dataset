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
        permissions.add(permission);
    }

    public boolean hasPermission(String permission) {
        return permissions.contains(permission);
    }

    public String getUsername() {
        return username;
    }

    public static void main(String[] args) {
        User user = new User("john_doe");
        user.addPermission("read");
        user.addPermission("write");

        System.out.println("User " + user.getUsername() + " has read permission: " + user.hasPermission("read"));
        System.out.println("User " + user.getUsername() + " has write permission: " + user.hasPermission("write"));
        System.out.println("User " + user.getUsername() + " has delete permission: " + user.hasPermission("delete"));
    }
}