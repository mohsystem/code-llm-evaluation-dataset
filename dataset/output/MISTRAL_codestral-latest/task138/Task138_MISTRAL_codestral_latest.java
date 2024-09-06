// Java

import java.util.Arrays;
import java.util.List;

public class Task138_MISTRAL_codestral_latest {
    private String name;
    private List<String> permissions;

    public Task138_MISTRAL_codestral_latest(String name, List<String> permissions) {
        this.name = name;
        this.permissions = permissions;
    }

    public boolean hasPermission(String permission) {
        return permissions.contains(permission);
    }

    // Example usage
    public static void main(String[] args) {
        Task138_MISTRAL_codestral_latest user = new Task138_MISTRAL_codestral_latest("John", Arrays.asList("read", "write"));
        System.out.println(user.hasPermission("read"));  // true
        System.out.println(user.hasPermission("execute"));  // false
    }
}