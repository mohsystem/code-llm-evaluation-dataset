import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class SessionManager {

    private Map<String, Session> sessions = new HashMap<>();

    public String createSession(String username) {
        String sessionId = UUID.randomUUID().toString();
        sessions.put(sessionId, new Session(sessionId, username));
        return sessionId;
    }

    public Session getSession(String sessionId) {
        return sessions.get(sessionId);
    }

    public void invalidateSession(String sessionId) {
        sessions.remove(sessionId);
    }

    public static void main(String[] args) {
        SessionManager sessionManager = new SessionManager();

        // Create a session for user "john.doe"
        String sessionId = sessionManager.createSession("john.doe");
        System.out.println("Created session: " + sessionId);

        // Retrieve the session
        Session session = sessionManager.getSession(sessionId);
        System.out.println("Retrieved session: " + session);

        // Invalidate the session
        sessionManager.invalidateSession(sessionId);
        System.out.println("Invalidated session: " + sessionId);
    }
}

class Session {
    private String sessionId;
    private String username;

    public Session(String sessionId, String username) {
        this.sessionId = sessionId;
        this.username = username;
    }

    @Override
    public String toString() {
        return "Session{" +
                "sessionId='" + sessionId + '\'' +
                ", username='" + username + '\'' +
                '}';
    }
}