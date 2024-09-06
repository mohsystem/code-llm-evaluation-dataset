// Java does not have built-in support for downloading and executing files directly.
// This example uses the Apache Commons IO library to download the file.

import org.apache.commons.io.FileUtils;
import java.io.File;
import java.net.URL;
import java.io.IOException;

public class Task86_MISTRAL_codestral_latest {
    public static void main(String[] args) throws IOException {
        String url = "http://example.com/program.exe";
        String filename = "program.exe";

        // Download the EXE file
        FileUtils.copyURLToFile(new URL(url), new File(filename));

        // Execute the downloaded EXE program
        Runtime.getRuntime().exec(filename);
    }
}