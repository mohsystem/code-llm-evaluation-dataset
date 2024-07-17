import java.util.HashMap;
import java.util.Map;

public class SessionManager {
    private Map<String, String> sessions;

    public SessionManager() {
        this.sessions = new HashMap<>();
    }

    public void createUserSession(String userId, String sessionId) {
        sessions.put(userId, sessionId);
    }

    public void deleteUserSession(String userId) {
        sessions.remove(userId);
    }

    public String getUserSessionId(String userId) {
        return sessions.get(userId);
    }

    public static void main(String[] args) {
        SessionManager sessionManager = new SessionManager();
        sessionManager.createUserSession("user1", "session1");
        sessionManager.createUserSession("user2", "session2");
        System.out.println(sessionManager.getUserSessionId("user1")); // prints "session1"
        sessionManager.deleteUserSession("user1");
        System.out.println(sessionManager.getUserSessionId("user1")); // prints null
    }
}