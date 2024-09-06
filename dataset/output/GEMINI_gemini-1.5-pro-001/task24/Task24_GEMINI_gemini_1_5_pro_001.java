public class Task24_GEMINI_gemini_1_5_pro_001 {
  public static boolean validatePin(String pin) {
    return pin.matches("^\\d{4}$|^\\d{6}$");
  }
}