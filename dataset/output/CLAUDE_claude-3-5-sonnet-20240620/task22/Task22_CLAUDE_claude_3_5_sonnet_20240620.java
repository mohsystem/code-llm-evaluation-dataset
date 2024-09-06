
import java.util.List;
import java.util.stream.Collectors;

public class Task22_CLAUDE_claude_3_5_sonnet_20240620 {
    public static List<Object> filterList(final List<Object> list) {
        return list.stream()
                   .filter(x -> x instanceof Integer)
                   .collect(Collectors.toList());
    }
}
