public class Task17_GEMINI_gemini_1_5_pro_001 {

  public String toJadenCase(String phrase) {
    if (phrase == null || phrase.isEmpty()) {
      return null;
    }
    String result = "";
    String[] words = phrase.split(" ");
    for (String word : words) {
      result += word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase() + " ";
    }
    return result.trim();
  }
}