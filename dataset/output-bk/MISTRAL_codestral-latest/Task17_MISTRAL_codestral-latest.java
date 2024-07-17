// Java
public class Main {
    public static String toJadenCase(String phrase) {
        if (phrase == null || phrase.equals(""))
            return null;

        String[] words = phrase.split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1);
        }
        return String.join(" ", words);
    }

    public static void main(String[] args) {
        System.out.println(toJadenCase("How can mirrors be real if our eyes aren't real"));
    }
}