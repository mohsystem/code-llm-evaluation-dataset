import java.util.ArrayList;
import java.util.List;

public class CountSmallerElements {
    public static List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = i+1; j < nums.length; j++) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }
            result.add(count);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {5, 2, 6, 1};
        List<Integer> result = countSmaller(nums);
        System.out.println(result);
    }
}