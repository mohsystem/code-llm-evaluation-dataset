import java.security.MessageDigest;
import java.util.HashMap;
import java.util.Map;

class UserAuth {
    private Map<String, String> users = new HashMap<>();

    public void addUser(String username, String password) throws Exception {
        String hashed = hashPassword(password);
        users.put(username, hashed);
    }

    public boolean authenticate(String username, String password) throws Exception {
        String hashed = hashPassword(password);
        return hashed.equals(users.get(username));
    }

    private String hashPassword(String password) throws Exception {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashBytes = md.digest(password.getBytes());
        StringBuilder sb = new StringBuilder();
        for (byte b : hashBytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        UserAuth auth = new UserAuth();
        auth.addUser("user", "pass");
        System.out.println(auth.authenticate("user", "pass"));
        System.out.println(auth.authenticate("user", "wrongpass"));
    }
}