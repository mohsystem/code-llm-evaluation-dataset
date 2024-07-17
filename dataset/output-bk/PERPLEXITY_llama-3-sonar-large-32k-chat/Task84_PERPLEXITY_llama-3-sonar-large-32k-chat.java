import java.util.UUID;

public class SessionIDGenerator {
    public static void main(String[] args) {
        String sessionId = UUID.randomUUID().toString();
        System.out.println("Session ID: " + sessionId);
    }
}