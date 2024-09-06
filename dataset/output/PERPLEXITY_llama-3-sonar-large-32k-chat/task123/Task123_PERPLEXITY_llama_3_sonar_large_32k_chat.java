import java.util.HashMap;
import java.util.Map;

public class Task123_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private Map<Integer, String> sessions;

    public Task123_PERPLEXITY_llama_3_sonar_large_32k_chat() {
        this.sessions = new HashMap<>();
    }

    public void createSession(int userId, String username) {
        this.sessions.put(userId, username);
        System.out.println("Session created for user " + username + " with ID " + userId);
    }

    public String getUsername(int userId) {
        return this.sessions.get(userId);
    }

    public void deleteSession(int userId) {
        if (this.sessions.containsKey(userId)) {
            this.sessions.remove(userId);
            System.out.println("Session deleted for user ID " + userId);
        } else {
            System.out.println("No session found for user ID " + userId);
        }
    }

    public static void main(String[] args) {
        Task123_PERPLEXITY_llama_3_sonar_large_32k_chat manager = new Task123_PERPLEXITY_llama_3_sonar_large_32k_chat();
        manager.createSession(1, "John");
        manager.createSession(2, "Alice");
        System.out.println(manager.getUsername(1));  // Output: John
        manager.deleteSession(2);
    }
}