import java.util.ArrayList;
import java.util.List;

public class Task25_MISTRAL_codestral_latest {
    public static List<String> number(List<String> lines) {
        List<String> numberedLines = new ArrayList<>();
        for (int i = 0; i < lines.size(); i++) {
            numberedLines.add((i + 1) + ": " + lines.get(i));
        }
        return numberedLines;
    }
}