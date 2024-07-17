import java.io.*;
import java.util.zip.*;

public class ArchiveExtractor {

    public static void extractZip(String archivePath, String extractPath) throws IOException {
        try (ZipInputStream zis = new ZipInputStream(new FileInputStream(archivePath))) {
            ZipEntry zipEntry = zis.getNextEntry();
            while (zipEntry != null) {
                String fileName = zipEntry.getName();
                File newFile = new File(extractPath + File.separator + fileName);

                if (zipEntry.isDirectory()) {
                    newFile.mkdirs();
                } else {
                    newFile.getParentFile().mkdirs();
                    try (FileOutputStream fos = new FileOutputStream(newFile)) {
                        byte[] buffer = new byte[1024];
                        int len;
                        while ((len = zis.read(buffer)) > 0) {
                            fos.write(buffer, 0, len);
                        }
                    }
                }
                zipEntry = zis.getNextEntry();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the path to the archive file: ");
        String archiveFile = reader.readLine();
        System.out.print("Enter the directory to extract to (leave blank to extract to current directory): ");
        String outputDir = reader.readLine();

        if (outputDir.isEmpty()) {
            outputDir = ".";
        }

        if (archiveFile.toLowerCase().endsWith(".zip")) {
            extractZip(archiveFile, outputDir);
        } else {
            System.out.println("Unsupported archive format.");
        }
    }
}