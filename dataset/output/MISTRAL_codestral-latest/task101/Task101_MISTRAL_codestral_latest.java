// Java
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Task101_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        try {
            File file = new File("script.sh");
            if (file.createNewFile()) {
                FileWriter writer = new FileWriter(file);
                writer.write("#!/bin/bash\necho \"Hello, World!\"");
                writer.close();
                Runtime.getRuntime().exec("chmod +x script.sh");
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}