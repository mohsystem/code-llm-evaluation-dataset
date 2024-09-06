import java.util.*;

public class Task164_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String[] lastNameLensort(String[] names) {
        Arrays.sort(names, new Comparator<String>() {
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
        return names;
    }
}