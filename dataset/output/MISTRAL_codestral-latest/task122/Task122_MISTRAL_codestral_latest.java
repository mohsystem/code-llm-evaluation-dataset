// Java
import java.util.HashMap;
import java.util.Map;

public class Task122_MISTRAL_codestral_latest {
    private static Map<String, String> passwords = new HashMap<>();

    public static void signup(String username, String password) {
        passwords.put(username, password);
    }

    // Example usage
    public static void main(String[] args) {
        signup("user1", "password1");
    }
}