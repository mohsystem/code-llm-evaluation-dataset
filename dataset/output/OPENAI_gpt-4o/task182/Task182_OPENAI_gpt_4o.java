import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Task182_OPENAI_gpt_4o {

    public static String cleanNumber(String number) {
        number = number.replaceAll("[^0-9]", "");
        if (number.startsWith("1") && number.length() == 11) {
            number = number.substring(1);
        }
        return number;
    }

    public static void main(String[] args) {
        List<String> numbers = Arrays.asList("+1 (613)-995-0253", "613-995-0253", "1 613 995 0253", "613.995.0253");
        List<String> cleanedNumbers = new ArrayList<>();
        for (String number : numbers) {
            cleanedNumbers.add(cleanNumber(number));
        }
        System.out.println(cleanedNumbers);
    }
}