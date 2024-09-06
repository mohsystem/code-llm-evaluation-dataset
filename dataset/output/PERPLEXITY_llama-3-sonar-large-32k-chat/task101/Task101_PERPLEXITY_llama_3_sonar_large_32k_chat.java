// Java does not have a built-in way to create executable files, so we'll use Runtime to execute a command
import java.io.FileWriter;
import java.io.IOException;

public class Task101_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws IOException {
        FileWriter writer = new FileWriter("script.sh");
        writer.write("#!/bin/bash\necho 'Hello World'");
        writer.close();
        Runtime.getRuntime().exec("chmod +x script.sh");
    }
}