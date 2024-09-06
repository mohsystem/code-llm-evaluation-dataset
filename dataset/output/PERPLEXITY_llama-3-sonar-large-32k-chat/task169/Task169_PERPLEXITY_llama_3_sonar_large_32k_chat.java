import java.util.*;

public class Task169_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public List<Integer> countSmaller(int[] nums) {
        Integer[] indices = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            indices[i] = i;
        }
        Arrays.sort(indices, (a, b) -> nums[b] - nums[a]);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int idx = Arrays.binarySearch(indices, i);
            res.add(idx < 0 ? -(idx + 1) : idx);
        }
        return res;
    }
}