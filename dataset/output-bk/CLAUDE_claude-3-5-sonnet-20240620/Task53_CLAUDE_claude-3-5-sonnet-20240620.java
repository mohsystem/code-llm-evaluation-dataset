
import java.util.*;
import java.time.LocalDateTime;
import java.time.Duration;

class Session {
    private String sessionId;
    private String userId;
    private LocalDateTime creationTime;
    private LocalDateTime lastAccessTime;

    public Session(String sessionId, String userId) {
        this.sessionId = sessionId;
        this.userId = userId;
        this.creationTime = LocalDateTime.now();
        this.lastAccessTime = LocalDateTime.now();
    }

    public String getSessionId() { return sessionId; }
    public String getUserId() { return userId; }
    public LocalDateTime getCreationTime() { return creationTime; }
    public LocalDateTime getLastAccessTime() { return lastAccessTime; }
    public void updateLastAccessTime() { lastAccessTime = LocalDateTime.now(); }
}

class SessionManager {
    private Map<String, Session> sessions;
    private static final int SESSION_TIMEOUT_MINUTES = 30;

    public SessionManager() {
        sessions = new HashMap<>();
    }

    public String createSession(String userId) {
        String sessionId = UUID.randomUUID().toString();
        Session session = new Session(sessionId, userId);
        sessions.put(sessionId, session);
        return sessionId;
    }

    public boolean validateSession(String sessionId) {
        Session session = sessions.get(sessionId);
        if (session != null) {
            Duration duration = Duration.between(session.getLastAccessTime(), LocalDateTime.now());
            if (duration.toMinutes() < SESSION_TIMEOUT_MINUTES) {
                session.updateLastAccessTime();
                return true;
            } else {
                sessions.remove(sessionId);
            }
        }
        return false;
    }

    public void endSession(String sessionId) {
        sessions.remove(sessionId);
    }
}

public class WebSessionManager {
    public static void main(String[] args) {
        SessionManager manager = new SessionManager();

        // Example usage
        String userId = "user123";
        String sessionId = manager.createSession(userId);
        System.out.println("Session created: " + sessionId);

        boolean isValid = manager.validateSession(sessionId);
        System.out.println("Session valid: " + isValid);

        manager.endSession(sessionId);
        System.out.println("Session ended");

        isValid = manager.validateSession(sessionId);
        System.out.println("Session valid after ending: " + isValid);
    }
}
