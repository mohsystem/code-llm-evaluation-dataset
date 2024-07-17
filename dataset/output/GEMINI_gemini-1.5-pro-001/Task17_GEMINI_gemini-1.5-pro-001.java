class Solution {
  public String toJadenCase(String phrase) {
    if(phrase == null || phrase.equals("")) return null;
    String result = "";
    String[] arr = phrase.split(" ");
    for(int i = 0; i < arr.length; i++){
      result += arr[i].substring(0, 1).toUpperCase() + arr[i].substring(1).toLowerCase() + " ";
    }
    return result.trim();
  }
}