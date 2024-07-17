import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();
        TreeSet<Integer> sortedSet = new TreeSet<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            int index = sortedSet.headSet(nums[i]).size();
            result.add(index);
            sortedSet.add(nums[i]);
        }
        Collections.reverse(result);
        return result;
    }
}