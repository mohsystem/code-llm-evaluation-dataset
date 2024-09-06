import java.net.URL;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Task160_MISTRAL_codestral_latest {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a URL: ");
        String url = scanner.nextLine();
        URL obj = new URL(url);
        BufferedReader in = new BufferedReader(new InputStreamReader(obj.openStream()));
        String inputLine;
        while ((inputLine = in.readLine()) != null) {
            System.out.println(inputLine);
        }
        in.close();
    }
}