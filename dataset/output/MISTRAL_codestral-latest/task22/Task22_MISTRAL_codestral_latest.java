import java.util.List;
import java.util.stream.Collectors;

public class Task22_MISTRAL_codestral_latest {
    public static List<Object> filterList(final List<Object> list) {
        return list.stream()
                   .filter(i -> i instanceof Integer)
                   .collect(Collectors.toList());
    }
}