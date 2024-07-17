import java.util.UUID;

public class TokenGenerator {
    public static void main(String[] args) {
        System.out.println("Java Token: " + generateToken());
    }

    public static String generateToken() {
        return UUID.randomUUID().toString();
    }
}