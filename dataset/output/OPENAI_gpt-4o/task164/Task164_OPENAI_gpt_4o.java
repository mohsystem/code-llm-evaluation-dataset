import java.util.*;

public class Task164_OPENAI_gpt_4o {
    public static List<String> lastNameLensort(List<String> names) {
        names.sort(Comparator.comparing((String s) -> s.split(" ")[1].length())
                             .thenComparing(s -> s.split(" ")[1]));
        return names;
    }

    public static void main(String[] args) {
        List<String> names = Arrays.asList("Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman");
        List<String> result = lastNameLensort(names);
        System.out.println(result);
    }
}