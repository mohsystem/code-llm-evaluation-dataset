import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Task82_GEMINI_gemini_1_5_pro_001 {

  public static String hashPassword(String password, String salt) {
    try {
      MessageDigest md = MessageDigest.getInstance("SHA-256");
      md.update(salt.getBytes());
      byte[] hashedPassword = md.digest(password.getBytes());

      // Convert byte array to hexadecimal string
      StringBuilder sb = new StringBuilder();
      for (byte b : hashedPassword) {
        sb.append(String.format("%02x", b));
      }
      return sb.toString();

    } catch (NoSuchAlgorithmException e) {
      e.printStackTrace();
      return null;
    }
  }
}