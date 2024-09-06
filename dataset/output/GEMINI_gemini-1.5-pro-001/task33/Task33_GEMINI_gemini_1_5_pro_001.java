import java.util.Arrays;

public class Task33_GEMINI_gemini_1_5_pro_001 {
  public static int queueTime(int[] customers, int n) {
    if (customers.length == 0) {
        return 0;
    }
    if (n == 1) {
        int totalTime = 0;
        for (int time : customers) {
            totalTime += time;
        }
        return totalTime;
    }
    if (n >= customers.length) {
        int maxTime = 0;
        for (int time : customers) {
            if (time > maxTime) {
                maxTime = time;
            }
        }
        return maxTime;
    }
    int[] tills = new int[n];
    for (int customerTime : customers) {
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (tills[i] < tills[minIndex]) {
                minIndex = i;
            }
        }
        tills[minIndex] += customerTime;
    }
    Arrays.sort(tills);
    return tills[n - 1];
  }
}