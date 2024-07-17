import java.util.ArrayList;
import java.util.List;

public class Kata {
    public static List<Object> filterList(List<Object> list) {
        List<Object> newList = new ArrayList<>();
        for (Object obj : list) {
            if (obj instanceof Integer) {
                newList.add(obj);
            }
        }
        return newList;
    }
}