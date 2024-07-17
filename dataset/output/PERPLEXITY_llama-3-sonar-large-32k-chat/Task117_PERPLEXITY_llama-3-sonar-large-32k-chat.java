import java.io.*;
import java.util.zip.*;

public class ExtractArchive {
    public static void main(String[] args) {
        String archiveFile = "archive.zip";
        String extractDir = "extracted";

        try (ZipInputStream zipInputStream = new ZipInputStream(new FileInputStream(archiveFile))) {
            ZipEntry zipEntry;
            while ((zipEntry = zipInputStream.getNextEntry()) != null) {
                String filePath = extractDir + File.separator + zipEntry.getName();
                File file = new File(filePath);
                file.getParentFile().mkdirs();
                FileOutputStream fileOutputStream = new FileOutputStream(file);
                byte[] buffer = new byte[1024];
                int len;
                while ((len = zipInputStream.read(buffer)) > 0) {
                    fileOutputStream.write(buffer, 0, len);
                }
                fileOutputStream.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}