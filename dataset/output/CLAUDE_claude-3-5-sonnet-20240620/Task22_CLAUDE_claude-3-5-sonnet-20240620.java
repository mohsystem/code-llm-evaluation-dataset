
import java.util.List;
import java.util.stream.Collectors;

public class Kata {
    public static List<Object> filterList(List<Object> list) {
        return list.stream()
                   .filter(item -> item instanceof Integer)
                   .collect(Collectors.toList());
    }

    public static void main(String[] args) {
        System.out.println(filterList(List.of(1, 2, "a", "b")));
        System.out.println(filterList(List.of(1, "a", "b", 0, 15)));
        System.out.println(filterList(List.of(1, 2, "a", "b", "aasf", "1", "123", 123)));
    }
}
