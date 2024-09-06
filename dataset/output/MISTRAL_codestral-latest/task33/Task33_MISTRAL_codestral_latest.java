public class Task33_MISTRAL_codestral_latest {
    public static int queueTime(int[] customers, int n) {
        int[] tills = new int[n];
        for (int i : customers) {
            int minIndex = 0;
            for (int j = 1; j < n; j++) {
                if (tills[j] < tills[minIndex]) {
                    minIndex = j;
                }
            }
            tills[minIndex] += i;
        }
        int max = 0;
        for (int i : tills) {
            if (i > max) {
                max = i;
            }
        }
        return max;
    }
}