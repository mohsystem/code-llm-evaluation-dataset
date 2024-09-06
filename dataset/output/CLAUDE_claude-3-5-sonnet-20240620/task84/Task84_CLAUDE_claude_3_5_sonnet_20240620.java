
import java.util.UUID;

public class Task84_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String generateSessionId() {
        return UUID.randomUUID().toString();
    }

    public static void main(String[] args) {
        String sessionId = generateSessionId();
        System.out.println(sessionId);
    }
}
