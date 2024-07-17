import java.util.ArrayList;
import java.util.List;

class Permission {
    String name;

    public Permission(String name) {
        this.name = name;
    }
}

class User {
    String username;
    List<Permission> permissions = new ArrayList<>();

    public User(String username) {
        this.username = username;
    }

    public void addPermission(Permission permission) {
        if (!permissions.contains(permission)) {
            permissions.add(permission);
        }
    }

    public void removePermission(Permission permission) {
        permissions.remove(permission);
    }

    public boolean hasPermission(String permissionName) {
        return permissions.stream().anyMatch(p -> p.name.equals(permissionName));
    }
}

class Main {
    public static void main(String[] args) {
        Permission readPermission = new Permission("read");
        Permission writePermission = new Permission("write");

        User user1 = new User("john_doe");
        user1.addPermission(readPermission);

        User user2 = new User("jane_doe");
        user2.addPermission(readPermission);
        user2.addPermission(writePermission);

        System.out.println(user1.username + " has read permission: " + user1.hasPermission("read"));
        System.out.println(user1.username + " has write permission: " + user1.hasPermission("write"));

        System.out.println(user2.username + " has read permission: " + user2.hasPermission("read"));
        System.out.println(user2.username + " has write permission: " + user2.hasPermission("write"));
    }
}