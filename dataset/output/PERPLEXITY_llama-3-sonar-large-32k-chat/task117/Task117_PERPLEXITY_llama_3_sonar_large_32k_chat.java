import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class Task117_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void extractZip(String zipFile, String extractDir) throws Exception {
        File file = new File(zipFile);
        File extractDirFile = new File(extractDir);
        if (!extractDirFile.exists()) {
            extractDirFile.mkdirs();
        }
        ZipInputStream zipIn = new ZipInputStream(new FileInputStream(file));
        ZipEntry entry;
        while ((entry = zipIn.getNextEntry()) != null) {
            String filePath = extractDir + File.separator + entry.getName();
            if (!entry.isDirectory()) {
                extractFile(zipIn, filePath);
            } else {
                File dir = new File(filePath);
                dir.mkdirs();
            }
        }
    }

    private static void extractFile(ZipInputStream zipIn, String filePath) throws Exception {
        FileOutputStream fileOut = new FileOutputStream(filePath);
        byte[] buffer = new byte[1024];
        int len;
        while ((len = zipIn.read(buffer)) > 0) {
            fileOut.write(buffer, 0, len);
        }
        fileOut.close();
    }

    public static void main(String[] args) throws Exception {
        extractZip("example.zip", "extracted_zip");
    }
}