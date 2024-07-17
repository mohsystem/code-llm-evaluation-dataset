import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int[] result1 = twoSum(new int[]{1, 2, 3}, 4);
        System.out.println("[" + result1[0] + ", " + result1[1] + "]");

        int[] result2 = twoSum(new int[]{3, 2, 4}, 6);
        System.out.println("[" + result2[0] + ", " + result2[1] + "]");
    }
}