class Solution {
  public static String tweakLetters(String txt, int[] arr) {
    String newTxt = "";
    for (int i = 0; i < txt.length(); i++) {
      if (arr[i] == 1) {
        newTxt += (char) (txt.charAt(i) + 1);
      } else if (arr[i] == -1) {
        newTxt += (char) (txt.charAt(i) - 1);
      } else {
        newTxt += txt.charAt(i);
      }
    }
    return newTxt;
  }
}