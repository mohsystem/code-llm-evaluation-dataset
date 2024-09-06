import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class Task53_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private Map<String, String> sessions;

    public Task53_PERPLEXITY_llama_3_sonar_large_32k_chat() {
        this.sessions = new HashMap<>();
    }

    public String createSession(String userId) {
        String sessionId = generateSessionId();
        sessions.put(sessionId, userId);
        return sessionId;
    }

    private String generateSessionId() {
        return UUID.randomUUID().toString();
    }

    public String getUserId(String sessionId) {
        return sessions.get(sessionId);
    }

    public void invalidateSession(String sessionId) {
        sessions.remove(sessionId);
    }

    public static void main(String[] args) {
        Task53_PERPLEXITY_llama_3_sonar_large_32k_chat sessionManager = new Task53_PERPLEXITY_llama_3_sonar_large_32k_chat();

        // create a session
        String sessionId = sessionManager.createSession("user1");
        System.out.println("Session ID: " + sessionId);

        // get user id from session id
        String userId = sessionManager.getUserId(sessionId);
        System.out.println("User ID: " + userId);

        // invalidate session
        sessionManager.invalidateSession(sessionId);
        System.out.println("Session invalidated");
    }
}