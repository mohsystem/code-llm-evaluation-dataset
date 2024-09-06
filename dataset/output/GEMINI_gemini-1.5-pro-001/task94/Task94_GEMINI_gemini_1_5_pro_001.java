import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Task94_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task94_GEMINI_gemini_1_5_pro_001 <file_path>");
            return;
        }

        String filePath = args[0];
        List<KeyValuePair> keyValuePairs = readFileAndSort(filePath);

        for (KeyValuePair pair : keyValuePairs) {
            System.out.println(pair.getKey() + " " + pair.getValue());
        }
    }

    private static List<KeyValuePair> readFileAndSort(String filePath) {
        List<KeyValuePair> keyValuePairs = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ", 2);
                keyValuePairs.add(new KeyValuePair(parts[0], parts[1]));
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        Collections.sort(keyValuePairs, Comparator.comparing(KeyValuePair::getKey));
        return keyValuePairs;
    }

    private static class KeyValuePair {
        private String key;
        private String value;

        public KeyValuePair(String key, String value) {
            this.key = key;
            this.value = value;
        }

        public String getKey() {
            return key;
        }

        public String getValue() {
            return value;
        }
    }
}