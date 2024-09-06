import java.util.ArrayList;
import java.util.List;

public class Task25_OPENAI_gpt_4o {
    public static List<String> number(List<String> lines) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < lines.size(); i++) {
            result.add((i + 1) + ": " + lines.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(number(new ArrayList<>()));  // []
        List<String> list = new ArrayList<>();
        list.add("a");
        list.add("b");
        list.add("c");
        System.out.println(number(list));  // ["1: a", "2: b", "3: c"]
    }
}