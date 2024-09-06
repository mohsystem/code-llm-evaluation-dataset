import java.util.ArrayList;
import java.util.List;

public class Task22_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static List<Integer> filterList(List<Object> list) {
        List<Integer> result = new ArrayList<>();
        for (Object obj : list) {
            if (obj instanceof Integer) {
                result.add((Integer) obj);
            }
        }
        return result;
    }
}