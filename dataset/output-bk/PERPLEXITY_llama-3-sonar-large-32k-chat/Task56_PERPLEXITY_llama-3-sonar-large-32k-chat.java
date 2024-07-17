import java.util.UUID;

public class TokenGenerator {
    public static void main(String[] args) {
        String token = UUID.randomUUID().toString();
        System.out.println("Token: " + token);
    }
}