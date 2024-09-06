import java.util.*;

public class Task33_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static int queueTime(int[] customers, int n) {
        if (customers.length == 0) {
            return 0;
        }
        int[] tills = new int[n];
        for (int time : customers) {
            int minTill = getMinIndex(tills);
            tills[minTill] += time;
        }
        return getMax(tills);
    }

    private static int getMinIndex(int[] arr) {
        int min = arr[0];
        int index = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
                index = i;
            }
        }
        return index;
    }

    private static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}