import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.Map;

class Session {
    String username;
    String sessionId;
    LocalDateTime createdAt;

    public Session(String username) {
        this.username = username;
        this.createdAt = LocalDateTime.now();
    }

    public void createSession() {
        // In a real application, generate a unique session ID
        this.sessionId = "session_" + username;
    }

    public boolean isValid() {
        // In a real application, check for session expiry
        return true;
    }
}

class SessionManager {
    Map<String, Session> sessions = new HashMap<>();

    public String createSession(String username) {
        Session session = new Session(username);
        session.createSession();
        sessions.put(session.sessionId, session);
        return session.sessionId;
    }

    public Session getSession(String sessionId) {
        return sessions.get(sessionId);
    }

    public void deleteSession(String sessionId) {
        sessions.remove(sessionId);
    }
}

public class Task123_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        SessionManager sessionManager = new SessionManager();

        // Create a new session
        String sessionId = sessionManager.createSession("user1");
        System.out.println("Session created for user1 with ID: " + sessionId);

        // Get the session
        Session session = sessionManager.getSession(sessionId);
        if (session.isValid()) {
            System.out.println("Session is valid for user: " + session.username);
        } else {
            System.out.println("Session is not valid");
        }

        // Delete the session
        sessionManager.deleteSession(sessionId);
        System.out.println("Session with ID " + sessionId + " deleted");
    }
}