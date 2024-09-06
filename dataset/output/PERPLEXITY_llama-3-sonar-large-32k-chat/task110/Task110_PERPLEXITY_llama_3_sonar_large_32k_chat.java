import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Scanner;

public class Task110_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a URL: ");
        String url = scanner.nextLine();
        if (validateUrl(url)) {
            System.out.println("URL is valid");
        } else {
            System.out.println("URL is not valid");
        }
    }

    public static boolean validateUrl(String url) {
        String pattern = "^(https?|ftp|file)://[-A-Za-z0-9+&@#/%?=~_|!:,.;]*[-A-Za-z0-9+&@#/%=~_|]";
        Pattern r = Pattern.compile(pattern);
        Matcher m = r.matcher(url);
        return m.matches();
    }
}