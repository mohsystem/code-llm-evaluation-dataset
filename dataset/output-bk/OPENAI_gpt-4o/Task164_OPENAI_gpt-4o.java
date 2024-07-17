import java.util.*;

public class Main {

    public static List<String> lastNameLensort(List<String> names) {
        names.sort((a, b) -> {
            String lastNameA = a.split(" ")[1];
            String lastNameB = b.split(" ")[1];
            if (lastNameA.length() != lastNameB.length()) {
                return lastNameA.length() - lastNameB.length();
            } else {
                return lastNameA.compareTo(lastNameB);
            }
        });
        return names;
    }

    public static void main(String[] args) {
        List<String> names = new ArrayList<>(Arrays.asList(
            "Jennifer Figueroa",
            "Heather Mcgee",
            "Amanda Schwartz",
            "Nicole Yoder",
            "Melissa Hoffman"
        ));

        System.out.println(lastNameLensort(names));
    }
}