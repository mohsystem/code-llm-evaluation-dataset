import java.security.SecureRandom;

public class Task56_GEMINI_gemini_1_5_pro_001 {
  public static void main(String[] args) {
    int tokenLength = 32;
    String token = generateToken(tokenLength);
    System.out.println(token);
  }

  private static String generateToken(int length) {
    SecureRandom random = new SecureRandom();
    String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    StringBuilder sb = new StringBuilder(length);
    for (int i = 0; i < length; i++) {
      int randomIndex = random.nextInt(characters.length());
      sb.append(characters.charAt(randomIndex));
    }
    return sb.toString();
  }
}