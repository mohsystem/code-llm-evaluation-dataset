
import java.time.Instant;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

class Session {
    String sessionId;
    String userId;
    Instant createdAt;
    Instant lastAccessed;

    Session(String userId) {
        this.sessionId = UUID.randomUUID().toString();
        this.userId = userId;
        this.createdAt = Instant.now();
        this.lastAccessed = Instant.now();
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
            if (Instant.now().getEpochSecond() - session.lastAccessed.getEpochSecond() > sessionTimeout) {
                destroySession(sessionId);
                return null;
            }
            session.lastAccessed = Instant.now();
        }
        return session;
    }

    void destroySession(String sessionId) {
        sessions.remove(sessionId);
    }

    void cleanupExpiredSessions() {
        Instant now = Instant.now();
        sessions.entrySet().removeIf(entry ->
                now.getEpochSecond() - entry.getValue().lastAccessed.getEpochSecond() > sessionTimeout);
    }

    public static void main(String[] args) {
        SessionManager sessionManager = new SessionManager(1800); // 30 minutes timeout

        // Create a new session
        String userId = "user123";
        String sessionId = sessionManager.createSession(userId);
        System.out.println("New session created: " + sessionId);

        // Get session
        Session session = sessionManager.getSession(sessionId);
        if (session != null) {
            System.out.println("Session found for user: " + session.userId);
        } else {
            System.out.println("Session not found");
        }

        // Cleanup expired sessions
        sessionManager.cleanupExpiredSessions();

        // Destroy session
        sessionManager.destroySession(sessionId);
        System.out.println("Session destroyed");
    }
}
