import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class SortKeyValueFile {
    public static void main(String[] args) {
        // Check if filename argument is provided
        if (args.length < 1) {
            System.err.println("Usage: java SortKeyValueFile <filename>");
            return;
        }

        String filename = args[0];

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            Map<String, String> keyValueMap = new TreeMap<>();

            String line;
            while ((line = br.readLine()) != null) {
                // Assuming key and value are separated by a space " "
                String[] parts = line.split(" ", 2);
                if (parts.length == 2) {
                    keyValueMap.put(parts[0], parts[1]);
                } else {
                    System.err.println("Invalid format on line: " + line);
                }
            }

            // Print sorted key-value pairs
            for (Map.Entry<String, String> entry : keyValueMap.entrySet()) {
                System.out.println(entry.getKey() + " " + entry.getValue());
            }

        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
}