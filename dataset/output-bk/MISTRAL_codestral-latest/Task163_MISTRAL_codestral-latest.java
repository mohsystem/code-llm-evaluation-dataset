public class Main {
    public static int longestRun(int[] arr) {
        if (arr.length == 0) {
            return 0;
        }

        int longestSequence = 1;
        int currentSequence = 1;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] - 1) {
                currentSequence++;
            } else {
                longestSequence = Math.max(longestSequence, currentSequence);
                currentSequence = 1;
            }
        }

        return Math.max(longestSequence, currentSequence);
    }
}