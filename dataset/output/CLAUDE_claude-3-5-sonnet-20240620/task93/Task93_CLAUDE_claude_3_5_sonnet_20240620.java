
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class Task93_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task93_CLAUDE_claude_3_5_sonnet_20240620 <filename>");
            return;
        }

        String filename = args[0];
        Map<String, String> records = new TreeMap<>();

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(":", 2);
                if (parts.length == 2) {
                    records.put(parts[0].trim(), parts[1].trim());
                } else {
                    System.out.println("Warning: Skipping invalid line: " + line);
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
            return;
        }

        for (Map.Entry<String, String> entry : records.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}
