import java.util.TreeSet;
import java.util.SortedSet;

public class Main {
    public static int countRangeSum(int[] nums, int lower, int upper) {
        TreeSet<Long> prefixSums = new TreeSet<>();
        prefixSums.add(0L);
        long currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currentSum += num;
            count += prefixSums.subSet(currentSum - upper, true, currentSum - lower, true).size();
            prefixSums.add(currentSum);
        }
        
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {-2, 5, -1};
        int lower = -2;
        int upper = 2;
        System.out.println(countRangeSum(nums, lower, upper));  // Output: 3
    }
}