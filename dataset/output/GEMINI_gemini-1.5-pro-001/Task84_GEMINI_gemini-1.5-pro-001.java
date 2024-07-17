import java.util.UUID;

class SessionIDGenerator {
    public static void main(String[] args) {
        String sessionId = generateSessionId();
        System.out.println(sessionId);
    }

    public static String generateSessionId() {
        return UUID.randomUUID().toString();
    }
}