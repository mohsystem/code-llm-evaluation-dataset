import java.util.PriorityQueue;
import java.util.Queue;

public class Checkout {
    public static int queueTime(int[] customers, int n) {
        Queue<Integer> tills = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            tills.add(0);
        }
        for (int time : customers) {
            int current = tills.poll();
            tills.add(current + time);
        }
        int totalTime = 0;
        while (!tills.isEmpty()) {
            totalTime = tills.poll();
        }
        return totalTime;
    }
    
    public static void main(String[] args) {
        System.out.println(queueTime(new int[]{5, 3, 4}, 1)); // should return 12
        System.out.println(queueTime(new int[]{10, 2, 3, 3}, 2)); // should return 10
        System.out.println(queueTime(new int[]{2, 3, 10}, 2)); // should return 12
    }
}