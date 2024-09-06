import java.util.Arrays;
import java.util.Collections;

public class Task147_MISTRAL_codestral_latest {
    public static int findKthLargest(int[] nums, int k) {
        Integer[] numsBoxed = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(numsBoxed, Collections.reverseOrder());
        return numsBoxed[k - 1];
    }
}