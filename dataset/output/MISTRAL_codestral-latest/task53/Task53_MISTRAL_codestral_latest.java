// Java
public class Task53_MISTRAL_codestral_latest {
    private String userId;
    private boolean isActive;

    public Task53_MISTRAL_codestral_latest(String userId) {
        this.userId = userId;
        this.isActive = true;
    }

    // Getters and setters for userId and isActive
}

// Example usage:
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Map<String, Session> userSessions = new HashMap<>();
        String userId = "123";
        userSessions.put(userId, new Task53_MISTRAL_codestral_latest(userId));
    }
}