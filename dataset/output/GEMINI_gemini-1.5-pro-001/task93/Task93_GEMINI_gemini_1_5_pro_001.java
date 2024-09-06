import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class Task93_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: java Task93_GEMINI_gemini_1_5_pro_001 <file_path>");
            return;
        }

        String filePath = args[0];
        Map<String, String> sortedRecords = readFileAndSort(filePath);

        for (Map.Entry<String, String> entry : sortedRecords.entrySet()) {
            System.out.println(entry.getKey() + "=" + entry.getValue());
        }
    }

    public static Map<String, String> readFileAndSort(String filePath) {
        Map<String, String> records = new TreeMap<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("=", 2);
                if (parts.length == 2) {
                    records.put(parts[0], parts[1]);
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }
        return records;
    }
}