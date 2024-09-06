public class Task19_GEMINI_gemini_1_5_pro_001 {
  public String spinWords(String sentence) {
    String[] words = sentence.split(" ");
    StringBuilder result = new StringBuilder();
    for (int i = 0; i < words.length; i++) {
      if (words[i].length() >= 5) {
        result.append(new StringBuilder(words[i]).reverse().toString());
      } else {
        result.append(words[i]);
      }
      if (i < words.length - 1) {
        result.append(" ");
      }
    }
    return result.toString();
  }
}