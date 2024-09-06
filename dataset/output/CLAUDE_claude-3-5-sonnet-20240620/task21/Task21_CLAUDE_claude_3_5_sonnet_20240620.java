
import java.util.ArrayList;
import java.util.List;

public class Task21_CLAUDE_claude_3_5_sonnet_20240620 {
    public static List<Integer> removeSmallest(List<Integer> numbers) {
        if (numbers.isEmpty()) return new ArrayList<>();
        List<Integer> result = new ArrayList<>(numbers);
        result.remove(result.indexOf(result.stream().min(Integer::compare).orElse(0)));
        return result;
    }
}
