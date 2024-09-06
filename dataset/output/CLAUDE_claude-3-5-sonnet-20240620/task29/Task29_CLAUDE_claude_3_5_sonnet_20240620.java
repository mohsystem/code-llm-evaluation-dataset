
import java.util.HashMap;
import java.util.Map;

public class Task29_CLAUDE_claude_3_5_sonnet_20240620 {
    public static int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            int complement = target - numbers[i];
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i};
            }
            numMap.put(numbers[i], i);
        }
        return null;
    }
}
