// Java
import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        String token = UUID.randomUUID().toString();
        System.out.println("Generated Token: " + token);
    }
}