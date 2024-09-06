public class Task163_GEMINI_gemini_1_5_pro_001 {
  public static int longestRun(int[] arr) {
    if (arr.length <= 1) {
      return arr.length;
    }

    int maxRun = 1;
    int currentRun = 1;

    for (int i = 1; i < arr.length; i++) {
      if (arr[i] == arr[i - 1] + 1 || arr[i] == arr[i - 1] - 1) {
        currentRun++;
      } else {
        currentRun = 1;
      }

      maxRun = Math.max(maxRun, currentRun);
    }

    return maxRun;
  }

  public static void main(String[] args) {
    int[] arr1 = {1, 2, 3, 5, 6, 7, 8, 9};
    int[] arr2 = {1, 2, 3, 10, 11, 15};
    int[] arr3 = {5, 4, 2, 1};
    int[] arr4 = {3, 5, 7, 10, 15};

    System.out.println(longestRun(arr1)); // Output: 5
    System.out.println(longestRun(arr2)); // Output: 3
    System.out.println(longestRun(arr3)); // Output: 2
    System.out.println(longestRun(arr4)); // Output: 1
  }
}