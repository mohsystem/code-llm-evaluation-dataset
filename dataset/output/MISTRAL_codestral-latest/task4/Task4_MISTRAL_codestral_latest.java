public class Task4_MISTRAL_codestral_latest {
    public static boolean isIsogram(String str) {
        str = str.toLowerCase();
        return str.length() == str.chars().distinct().count();
    }
}