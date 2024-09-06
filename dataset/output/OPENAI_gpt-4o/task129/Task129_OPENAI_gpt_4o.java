import java.io.*;
import java.net.*;

public class Task129_OPENAI_gpt_4o {
    public static String fetchFile(String fileName) {
        StringBuilder result = new StringBuilder();
        try {
            URL url = new URL("http://example.com/" + fileName);
            BufferedReader in = new BufferedReader(new InputStreamReader(url.openStream()));
            String inputLine;
            while ((inputLine = in.readLine()) != null)
                result.append(inputLine).append("\n");
            in.close();
        } catch (Exception e) {
            return "Failed to retrieve file: " + e.getMessage();
        }
        return result.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter file name: ");
        String fileName = reader.readLine();
        String fileContent = fetchFile(fileName);
        System.out.println(fileContent);
    }
}