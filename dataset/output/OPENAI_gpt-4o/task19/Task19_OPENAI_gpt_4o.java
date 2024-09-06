import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Task19_OPENAI_gpt_4o {
    public static String spinWords(String sentence) {
        List<String> words = Arrays.asList(sentence.split(" "));
        return words.stream()
            .map(word -> word.length() >= 5 ? new StringBuilder(word).reverse().toString() : word)
            .collect(Collectors.joining(" "));
    }

    public static void main(String[] args) {
        String[] examples = {"Hey fellow warriors", "This is a test", "This is another test"};
        for (String example : examples) {
            System.out.println(spinWords(example));
        }
    }
}