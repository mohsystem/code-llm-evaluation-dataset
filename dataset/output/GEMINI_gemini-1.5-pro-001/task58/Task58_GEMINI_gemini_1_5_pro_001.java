public class Task58_GEMINI_gemini_1_5_pro_001 {
  public static boolean XO(String text) {
    text = text.toLowerCase();
    return text.replace("x", "").length() == text.replace("o", "").length();
  }
}