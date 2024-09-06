import java.util.*;

class Main {
    public static int longestRun(int[] lst) {
        if (lst.length == 0) {
            return 0;
        }
        int maxRun = 1;
        int currentRun = 1;
        for (int i = 1; i < lst.length; i++) {
            if (lst[i] == lst[i-1] + 1 || lst[i] == lst[i-1] - 1) {
                currentRun += 1;
            } else {
                maxRun = Math.max(maxRun, currentRun);
                currentRun = 1;
            }
        }
        return Math.max(maxRun, currentRun);
    }

    public static void main(String[] args) {
        System.out.println(longestRun(new int[]{1, 2, 3, 5, 6, 7, 8, 9}));
        System.out.println(longestRun(new int[]{1, 2, 3, 10, 11, 15}));
        System.out.println(longestRun(new int[]{5, 4, 2, 1}));
        System.out.println(longestRun(new int[]{3, 5, 7, 10, 15}));
    }
}