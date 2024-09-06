public class Task17_OPENAI_gpt_4o {
    public static String toJadenCase(String phrase) {
        if (phrase == null || phrase.isEmpty()) {
            return null;
        }
        String[] words = phrase.split(" ");
        StringBuilder jadenCase = new StringBuilder();
        for (String word : words) {
            jadenCase.append(Character.toUpperCase(word.charAt(0)))
                     .append(word.substring(1)).append(" ");
        }
        return jadenCase.toString().trim();
    }

    public static void main(String[] args) {
        System.out.println(toJadenCase("How can mirrors be real if our eyes aren't real"));
    }
}