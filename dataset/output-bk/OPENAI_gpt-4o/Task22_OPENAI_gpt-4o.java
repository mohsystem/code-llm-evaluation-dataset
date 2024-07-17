import java.util.ArrayList;
import java.util.List;

public class Kata {
    public static List<Object> filterList(List<Object> list) {
        List<Object> filteredList = new ArrayList<>();
        for (Object item : list) {
            if (item instanceof Integer) {
                filteredList.add(item);
            }
        }
        return filteredList;
    }
    
    public static void main(String[] args) {
        System.out.println(filterList(List.of(1, 2, "a", "b"))); // [1, 2]
        System.out.println(filterList(List.of(1, "a", "b", 0, 15))); // [1, 0, 15]
        System.out.println(filterList(List.of(1, 2, "a", "b", "aasf", "1", "123", 123))); // [1, 2, 123]
    }
}