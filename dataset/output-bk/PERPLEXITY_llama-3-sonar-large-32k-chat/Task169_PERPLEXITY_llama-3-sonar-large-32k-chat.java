import java.util.*;

public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Integer[] indices = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            indices[i] = i;
        }
        Arrays.sort(indices, (a, b) -> nums[b] - nums[a]);
        int[] counts = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            counts[indices[i]] = i;
        }
        return Arrays.asList(counts);
    }
}