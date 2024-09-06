import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please provide a filename as argument.");
            return;
        }
        String filename = args[0];
        
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            List<String[]> records = new ArrayList<>();
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                records.add(parts);
            }
            reader.close();

            records.sort(Comparator.comparing(a -> a[0]));

            for (String[] record : records) {
                System.out.println(record[0] + " " + record[1]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}