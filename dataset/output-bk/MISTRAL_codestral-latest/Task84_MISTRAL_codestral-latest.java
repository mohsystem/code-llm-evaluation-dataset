import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        System.out.println(generateSessionId());
    }

    public static String generateSessionId() {
        return UUID.randomUUID().toString();
    }
}