import java.util.ArrayList;
import java.util.List;

public class Task21_MISTRAL_codestral_latest {
    public static List<Integer> removeSmallest(List<Integer> numbers) {
        if (!numbers.isEmpty()) {
            numbers.remove(numbers.indexOf(Collections.min(numbers)));
        }
        return numbers;
    }
}