import java.security.SecureRandom;
import java.math.BigInteger;

public class Task135_OPENAI_gpt_4o {
    private String token;

    public String generateToken(String sessionId) {
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[60];
        random.nextBytes(bytes);
        token = new BigInteger(1, bytes).toString(16) + sessionId;
        return token;
    }

    public boolean validateToken(String token, String sessionId) {
        return token.equals(this.token + sessionId);
    }

    public static void main(String[] args) {
        Task135_OPENAI_gpt_4o csrf = new Task135_OPENAI_gpt_4o();
        String sessionId = "12345ABC";
        String token = csrf.generateToken(sessionId);
        System.out.println("Token: " + token);
        System.out.println("Validation: " + csrf.validateToken(token, sessionId));
    }
}