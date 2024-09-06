import java.util.Arrays;

public class Task6_GEMINI_gemini_1_5_pro_001 {
    public static double findUniq(double arr[]) {
      Arrays.sort(arr);
      return arr[0] == arr[1] ? arr[arr.length-1] : arr[0];
    }
}