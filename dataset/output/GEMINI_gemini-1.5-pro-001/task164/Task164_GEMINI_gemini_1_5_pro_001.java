import java.util.Arrays;
import java.util.Comparator;

public class Task164_GEMINI_gemini_1_5_pro_001 {

    public static String[] lastNameLensort(String[] names) {
        Arrays.sort(names, Comparator.comparingInt(a -> a.split(" ")[1].length()));
        Arrays.sort(names, Comparator.comparing(a -> a.split(" ")[1]));
        return names;
    }
}