// Java

class User {
    private String username;
    private String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    // getters and setters
}

import java.util.ArrayList;
import java.util.List;

class Authentication {
    private List<User> users;

    public Authentication() {
        this.users = new ArrayList<>();
    }

    public void register(String username, String password) {
        User newUser = new User(username, password);
        users.add(newUser);
        System.out.println("User registered successfully.");
    }

    public void login(String username, String password) {
        for (User user : users) {
            if (user.getUsername().equals(username) && user.getPassword().equals(password)) {
                System.out.println("Login successful.");
                return;
            }
        }
        System.out.println("Invalid username or password.");
    }
}

public class Task136_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Authentication auth = new Authentication();
        auth.register("user1", "password1");
        auth.login("user1", "password1");
    }
}