import java.util.Random;

public class Task85_GEMINI_gemini_1_5_pro_001 {

  public static String generateRandomString(int length) {
    Random random = new Random();
    StringBuilder sb = new StringBuilder(length);
    for (int i = 0; i < length; i++) {
      char randomChar = (char) (random.nextInt(26) + (random.nextBoolean() ? 'a' : 'A'));
      sb.append(randomChar);
    }
    return sb.toString();
  }
}