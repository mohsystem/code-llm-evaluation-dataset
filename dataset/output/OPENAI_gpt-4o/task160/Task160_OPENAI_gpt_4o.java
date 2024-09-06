import java.util.Scanner;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

public class Task160_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a URL: ");
        String urlString = scanner.nextLine();

        try {
            URL url = new URL(urlString);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");

            Scanner responseScanner = new Scanner(conn.getInputStream());
            while (responseScanner.hasNextLine()) {
                System.out.println(responseScanner.nextLine());
            }
            responseScanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}