
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<Integer> removeSmallest(List<Integer> numbers) {
        if (numbers.isEmpty()) {
            return new ArrayList<>();
        }
        
        List<Integer> result = new ArrayList<>(numbers);
        int minIndex = 0;
        for (int i = 1; i < result.size(); i++) {
            if (result.get(i) < result.get(minIndex)) {
                minIndex = i;
            }
        }
        result.remove(minIndex);
        return result;
    }
}
