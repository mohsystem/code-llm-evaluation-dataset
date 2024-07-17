
import java.util.PriorityQueue;

public class Solution {
    public static int queueTime(int[] customers, int n) {
        PriorityQueue<Integer> tills = new PriorityQueue<>(n);
        
        for (int i = 0; i < n; i++) {
            tills.offer(0);
        }
        
        for (int customerTime : customers) {
            int tillTime = tills.poll();
            tills.offer(tillTime + customerTime);
        }
        
        int maxTime = 0;
        while (!tills.isEmpty()) {
            maxTime = tills.poll();
        }
        
        return maxTime;
    }
}
