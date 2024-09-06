
import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class Task25_CLAUDE_claude_3_5_sonnet_20240620 {
    public static List<String> number(List<String> lines) {
        List<String> result = new ArrayList<>();
        IntStream.range(0, lines.size())
                 .forEach(i -> result.add((i + 1) + ": " + lines.get(i)));
        return result;
    }
}
