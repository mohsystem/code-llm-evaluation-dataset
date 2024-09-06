public class Task59_MISTRAL_codestral_latest {
    public static String accum(String s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) result.append("-");
            result.append(Character.toUpperCase(s.charAt(i)));
            for (int j = 0; j < i; j++) {
                result.append(Character.toLowerCase(s.charAt(i)));
            }
        }
        return result.toString();
    }
}