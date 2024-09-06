public class Task20_GEMINI_gemini_1_5_pro_001 {
  public static long digPow(int n, int p) {
    String intString = String.valueOf(n);
    long sum = 0;
    for (int i = 0; i < intString.length(); ++i, ++p) {
      sum += Math.pow(Integer.parseInt(String.valueOf(intString.charAt(i))), p);
    }
    return (sum % n == 0) ? sum / n : -1;
  }
}