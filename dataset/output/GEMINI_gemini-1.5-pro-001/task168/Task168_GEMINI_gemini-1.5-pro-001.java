import java.util.Arrays;
class Solution {
  public static String tweakLetters(String txt, int[] arr) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < txt.length(); i++) {
      if (arr[i] == 1) {
        sb.append((char) (txt.charAt(i) + 1));
      } else if (arr[i] == -1) {
        sb.append((char) (txt.charAt(i) - 1));
      } else {
        sb.append(txt.charAt(i));
      }
    }
    return sb.toString();
  }
  public static void main(String[] args) {
    // test the code
    System.out.println(tweakLetters("apple", new int[]{0, 1, -1, 0, -1}));
    System.out.println(tweakLetters("many", new int[]{0, 0, 0, -1}));
    System.out.println(tweakLetters("rhino", new int[]{1, 1, 1, 1, 1}));
  }
}