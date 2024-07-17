import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        String[] names = {
          "Jennifer Figueroa",
          "Heather Mcgee",
          "Amanda Schwartz",
          "Nicole Yoder",
          "Melissa Hoffman"
        };
        lastNameLensort(names);
        for (String name : names) {
            System.out.println(name);
        }
    }

    public static void lastNameLensort(String[] names) {
        Arrays.sort(names, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                String[] split1 = s1.split(" ");
                String[] split2 = s2.split(" ");
                if (split1[1].length() != split2[1].length()) {
                    return split1[1].length() - split2[1].length();
                } else {
                    return split1[1].compareTo(split2[1]);
                }
            }
        });
    }
}