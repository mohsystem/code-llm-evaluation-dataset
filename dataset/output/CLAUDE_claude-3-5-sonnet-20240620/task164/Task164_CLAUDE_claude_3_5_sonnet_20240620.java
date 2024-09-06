
import java.util.*;

public class Task164_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String[] lastNameLensort(String[] names) {
        Arrays.sort(names, (a, b) -> {
            String[] aParts = a.split(" ");
            String[] bParts = b.split(" ");
            String aLast = aParts[aParts.length - 1];
            String bLast = bParts[bParts.length - 1];
            
            if (aLast.length() != bLast.length()) {
                return Integer.compare(aLast.length(), bLast.length());
            }
            return aLast.compareTo(bLast);
        });
        return names;
    }

    public static void main(String[] args) {
        String[] names = {
            "Jennifer Figueroa",
            "Heather Mcgee",
            "Amanda Schwartz",
            "Nicole Yoder",
            "Melissa Hoffman"
        };
        String[] sorted = lastNameLensort(names);
        System.out.println(Arrays.toString(sorted));
    }
}
