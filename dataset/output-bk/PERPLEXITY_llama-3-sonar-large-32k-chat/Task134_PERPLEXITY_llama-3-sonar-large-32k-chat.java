code here:
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

public class KeyManager {
    private Map<String, String> keys;

    public KeyManager() {
        this.keys = new HashMap<>();
    }

    public String generateKey(String username) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(username.getBytes());
            StringBuilder hexString = new StringBuilder();
            for (byte b : hash) {
                String hex = Integer.toHexString(0xff & b);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }
            String key = hexString.toString();
            this.keys.put(username, key);
            return key;
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public String getKey(String username) {
        return this.keys.get(username);
    }

    public void deleteKey(String username) {
        this.keys.remove(username);
    }

    public static void main(String[] args) {
        KeyManager manager = new KeyManager();
        System.out.println(manager.generateKey("user1"));
        System.out.println(manager.getKey("user1"));
        manager.deleteKey("user1");
        System.out.println(manager.getKey("user1"));
    }
}