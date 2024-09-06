import java.io.*;
import java.util.*;

public class Task94_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task94_OPENAI_gpt_4o <filename>");
            return;
        }

        String filename = args[0];
        List<String[]> records = readFile(filename);
        Collections.sort(records, Comparator.comparing(arr -> arr[0]));

        for (String[] record : records) {
            System.out.println(record[0] + " = " + record[1]);
        }
    }

    private static List<String[]> readFile(String filename) {
        List<String[]> records = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("=");
                records.add(parts);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return records;
    }
}