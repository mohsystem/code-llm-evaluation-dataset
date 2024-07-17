import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        throws IOException {
        String filePath = "script.sh";
        String fileContent = "#!/bin/bash
echo 'Hello World'";
        FileWriter writer = new FileWriter(filePath);
        writer.write(fileContent);
        writer.close();
        Runtime.getRuntime().exec("chmod +x " + filePath);
    }
}