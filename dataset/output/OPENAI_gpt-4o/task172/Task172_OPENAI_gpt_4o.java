import java.util.HashSet;
import java.util.Set;

public class Task172_OPENAI_gpt_4o {
    public static int distinctAASubstrings(String text) {
        Set<String> distinctSubstrings = new HashSet<>();
        int n = text.length();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j += 2) {
                String a = text.substring(i, (i + j + 1) / 2);
                String b = text.substring((i + j + 1) / 2, j + 1);
                if (a.equals(b)) {
                    distinctSubstrings.add(text.substring(i, j + 1));
                }
            }
        }
        
        return distinctSubstrings.size();
    }

    public static void main(String[] args) {
        String text1 = "abcabcabc";
        System.out.println(distinctAASubstrings(text1));
        
        String text2 = "leetcodeleetcode";
        System.out.println(distinctAASubstrings(text2));
    }
}