// Java
import java.util.Arrays;
import java.util.List;

public class User {
    private String name;
    private List<String> permissions;

    public User(String name, List<String> permissions) {
        this.name = name;
        this.permissions = permissions;
    }

    public boolean hasPermission(String permission) {
        return permissions.contains(permission);
    }

    // Example usage
    public static void main(String[] args) {
        User user = new User("John", Arrays.asList("read", "write"));
        System.out.println(user.hasPermission("read"));  // true
        System.out.println(user.hasPermission("execute"));  // false
    }
}