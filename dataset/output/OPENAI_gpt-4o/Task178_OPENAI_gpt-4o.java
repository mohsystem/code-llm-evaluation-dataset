import java.util.Deque;
import java.util.LinkedList;

public class Main {
    public static int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] P = new int[n + 1];
        for (int i = 0; i < n; ++i)
            P[i + 1] = P[i] + nums[i];

        int ans = n + 1;
        Deque<Integer> monoq = new LinkedList<>();

        for (int y = 0; y < P.length; ++y) {
            while (!monoq.isEmpty() && P[y] <= P[monoq.getLast()])
                monoq.pollLast();
            while (!monoq.isEmpty() && P[y] >= P[monoq.getFirst()] + k)
                ans = Math.min(ans, y - monoq.pollFirst());

            monoq.addLast(y);
        }

        return ans < n + 1 ? ans : -1;
    }

    public static void main(String[] args) {
        System.out.println(shortestSubarray(new int[]{1}, 1)); // Output: 1
        System.out.println(shortestSubarray(new int[]{1, 2}, 4)); // Output: -1
        System.out.println(shortestSubarray(new int[]{2, -1, 2}, 3)); // Output: 3
    }
}