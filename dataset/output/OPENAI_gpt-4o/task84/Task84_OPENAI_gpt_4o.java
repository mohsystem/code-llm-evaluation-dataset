import java.util.Random;

public class Task84_OPENAI_gpt_4o {

    public static String generateSessionID() {
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        Random random = new Random();
        StringBuilder sessionID = new StringBuilder();
        for (int i = 0; i < 16; i++) {
            sessionID.append(characters.charAt(random.nextInt(characters.length())));
        }
        return sessionID.toString();
    }

    public static void main(String[] args) {
        System.out.println("Java generated session ID: " + generateSessionID());
    }
}