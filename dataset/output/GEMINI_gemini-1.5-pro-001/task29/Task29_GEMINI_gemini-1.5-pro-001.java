import java.util.HashMap;
import java.util.Map;

class Solution {
    public static int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> nums = new HashMap<>();
        for (int index = 0; index < numbers.length; index++) {
            int complement = target - numbers[index];
            if (nums.containsKey(complement)) {
                return new int[] {nums.get(complement), index};
            }
            nums.put(numbers[index], index);
        }
        return new int[0]; 
    }
}