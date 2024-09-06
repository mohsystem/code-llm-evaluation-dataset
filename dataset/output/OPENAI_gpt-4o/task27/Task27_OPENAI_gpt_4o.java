import java.util.ArrayList;
import java.util.List;

public class Task27_OPENAI_gpt_4o {
    public static void main(String[] args) {
        System.out.println(findOutlier(new int[]{2, 4, 0, 100, 4, 11, 2602, 36}));  // Output: 11
        System.out.println(findOutlier(new int[]{160, 3, 1719, 19, 11, 13, -21}));  // Output: 160
    }

    public static int findOutlier(int[] integers) {
        List<Integer> odds = new ArrayList<>();
        List<Integer> evens = new ArrayList<>();
        
        for (int i : integers) {
            if (i % 2 == 0) {
                evens.add(i);
            } else {
                odds.add(i);
            }
        }
        
        return odds.size() == 1 ? odds.get(0) : evens.get(0);
    }
}