import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class CreateScriptFile {
    public static void main(String[] args) {
        try {
            File file = new File("script.sh");
            if (file.createNewFile()) {
                FileWriter writer = new FileWriter("script.sh");
                writer.write("#!/bin/bash
");
                writer.write("echo Hello, World!");
                writer.close();
                file.setExecutable(true, false);
                System.out.println("script.sh created and made executable.");
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}