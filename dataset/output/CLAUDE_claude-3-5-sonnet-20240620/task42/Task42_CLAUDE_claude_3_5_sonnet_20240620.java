
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Task42_CLAUDE_claude_3_5_sonnet_20240620 {
    private static Map<String, byte[]> users = new HashMap<>();
    private static final int SALT_LENGTH = 16;
    private static final int ITERATIONS = 10000;

    private static byte[] hashPassword(String password, byte[] salt) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.reset();
        md.update(salt);
        byte[] hashed = md.digest(password.getBytes());
        for (int i = 0; i < ITERATIONS; i++) {
            md.reset();
            hashed = md.digest(hashed);
        }
        byte[] result = new byte[salt.length + hashed.length];
        System.arraycopy(salt, 0, result, 0, salt.length);
        System.arraycopy(hashed, 0, result, salt.length, hashed.length);
        return result;
    }

    private static boolean verifyPassword(byte[] storedPassword, String providedPassword) throws NoSuchAlgorithmException {
        byte[] salt = Arrays.copyOfRange(storedPassword, 0, SALT_LENGTH);
        byte[] hashedProvided = hashPassword(providedPassword, salt);
        return Arrays.equals(storedPassword, hashedProvided);
    }

    public static boolean register(String username, String password) throws NoSuchAlgorithmException {
        if (users.containsKey(username)) {
            return false;
        }
        SecureRandom random = new SecureRandom();
        byte[] salt = new byte[SALT_LENGTH];
        random.nextBytes(salt);
        users.put(username, hashPassword(password, salt));
        return true;
    }

    public static boolean login(String username, String password) throws NoSuchAlgorithmException {
        if (!users.containsKey(username)) {
            return false;
        }
        return verifyPassword(users.get(username), password);
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        register("alice", "password123");
        System.out.println(login("alice", "password123")); // true
        System.out.println(login("alice", "wrongpassword")); // false
    }
}
