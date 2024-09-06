
import java.time.Instant;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

class Session {
    String sessionId;
    String userId;
    Instant creationTime;
    Instant lastActivity;

    Session(String userId) {
        this.sessionId = UUID.randomUUID().toString();
        this.userId = userId;
        this.creationTime = Instant.now();
        this.lastActivity = this.creationTime;
    }
}

class SessionManager {
    private Map<String, Session> sessions;
    private long sessionTimeout;

    SessionManager(long sessionTimeout) {
        this.sessions = new HashMap<>();
        this.sessionTimeout = sessionTimeout;
    }

    String createSession(String userId) {
        Session session = new Session(userId);
        sessions.put(session.sessionId, session);
        return session.sessionId;
    }

    Session getSession(String sessionId) {
        Session session = sessions.get(sessionId);
        if (session != null) {
            if (Instant.now().toEpochMilli() - session.lastActivity.toEpochMilli() > sessionTimeout) {
                destroySession(sessionId);
                return null;
            }
            session.lastActivity = Instant.now();
        }
        return session;
    }

    void destroySession(String sessionId) {
        sessions.remove(sessionId);
    }

    void cleanupExpiredSessions() {
        long currentTime = Instant.now().toEpochMilli();
        sessions.entrySet().removeIf(entry ->
                currentTime - entry.getValue().lastActivity.toEpochMilli() > sessionTimeout);
    }
}

public class Task123_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws InterruptedException {
        SessionManager sessionManager = new SessionManager(1800000); // 30 minutes timeout

        // Create a session
        String userId = "user123";
        String sessionId = sessionManager.createSession(userId);
        System.out.println("Session created for user " + userId + ": " + sessionId);

        // Get session
        Session session = sessionManager.getSession(sessionId);
        if (session != null) {
            System.out.println("Session found for user " + session.userId);
        } else {
            System.out.println("Session not found");
        }

        // Simulate session expiration
        Thread.sleep(2000);
        sessionManager = new SessionManager(1000); // Set timeout to 1 second for demonstration
        session = sessionManager.getSession(sessionId);
        if (session != null) {
            System.out.println("Session still active for user " + session.userId);
        } else {
            System.out.println("Session expired");
        }

        // Cleanup expired sessions
        sessionManager.cleanupExpiredSessions();
        System.out.println("Expired sessions cleaned up");
    }
}
