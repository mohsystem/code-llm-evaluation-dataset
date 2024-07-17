import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class SortKeyValueFile {

    public static void main(String[] args) throws IOException {
        // Replace "input.txt" with the actual input file name
        String inputFileName = "input.txt";

        // Use a TreeMap to store key-value pairs, which automatically sorts by key
        Map<String, String> sortedRecords = new TreeMap<>();

        // Read the input file and populate the TreeMap
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                // Assuming key and value are separated by a space
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    sortedRecords.put(parts[0], parts[1]);
                }
            }
        }

        // Print the sorted key-value pairs
        for (Map.Entry<String, String> entry : sortedRecords.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}