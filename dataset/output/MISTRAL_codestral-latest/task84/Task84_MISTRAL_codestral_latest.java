import java.util.UUID;

public class Task84_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        System.out.println(generateSessionId());
    }

    public static String generateSessionId() {
        return UUID.randomUUID().toString();
    }
}