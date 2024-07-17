import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

class UserSessionManager {
    private static Map<String, String> sessions = new HashMap<>();

    public static String createSession(String username) {
        String sessionId = UUID.randomUUID().toString();
        sessions.put(sessionId, username);
        return sessionId;
    }

    public static String getSession(String sessionId) {
        return sessions.get(sessionId);
    }

    public static void removeSession(String sessionId) {
        sessions.remove(sessionId);
    }

    public static void main(String[] args) {
        String sessionId = createSession("JohnDoe");
        System.out.println("Session ID: " + sessionId);
        System.out.println("User: " + getSession(sessionId));
        removeSession(sessionId);
        System.out.println("Session removed. User: " + getSession(sessionId));
    }
}