import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] lastNameLensort(String[] names) {
        Arrays.sort(names, new Comparator<String>() {
            @Override
            public int compare(String name1, String name2) {
                String[] parts1 = name1.split(" ");
                String[] parts2 = name2.split(" ");
                int lenDiff = parts1[1].length() - parts2[1].length();
                if (lenDiff != 0) {
                    return lenDiff;
                } else {
                    return parts1[1].compareTo(parts2[1]);
                }
            }
        });
        return names;
    }
}