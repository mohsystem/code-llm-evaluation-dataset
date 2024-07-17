import java.util.List;
import java.util.ArrayList;

public class LineNumbering {
    public static List<String> number(List<String> lines) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < lines.size(); i++) {
            result.add((i + 1) + ": " + lines.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> lines = List.of("a", "b", "c");
        System.out.println(number(lines));
    }
}