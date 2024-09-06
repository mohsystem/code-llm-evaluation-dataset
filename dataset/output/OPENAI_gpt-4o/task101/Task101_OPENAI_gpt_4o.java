import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Task101_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String filename = "script.sh";
        try {
            File file = new File(filename);
            if (file.createNewFile()) {
                FileWriter writer = new FileWriter(filename);
                writer.write("#!/bin/bash\n\necho 'Hello, World!'");
                writer.close();
                file.setExecutable(true);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}