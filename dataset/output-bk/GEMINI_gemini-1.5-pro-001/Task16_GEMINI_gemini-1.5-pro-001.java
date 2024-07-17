public class Solution {
  public static boolean solution(String str, String ending) {
    if (str.length() < ending.length()) {
      return false;
    }
    return str.substring(str.length() - ending.length()).equals(ending);
  }
  
  public static void main(String[] args) {
    System.out.println(solution("abc", "bc")); // true
    System.out.println(solution("abc", "d")); // false
  }
}