
import java.util.UUID;

public class SessionIDGenerator {
    public static String generateSessionID() {
        return UUID.randomUUID().toString();
    }

    public static void main(String[] args) {
        String sessionID = generateSessionID();
        System.out.println("Generated Session ID: " + sessionID);
    }
}
