
import java.io.*;
import java.util.zip.*;

public class ArchiveExtractor {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java ArchiveExtractor <archive_file> <output_directory>");
            return;
        }

        String archiveFile = args[0];
        String outputDir = args[1];

        try {
            extractZip(archiveFile, outputDir);
        } catch (IOException e) {
            System.err.println("Error extracting archive: " + e.getMessage());
        }
    }

    private static void extractZip(String zipFilePath, String destDirectory) throws IOException {
        File destDir = new File(destDirectory);
        if (!destDir.exists()) {
            destDir.mkdir();
        }

        try (ZipInputStream zipIn = new ZipInputStream(new FileInputStream(zipFilePath))) {
            ZipEntry entry = zipIn.getNextEntry();
            while (entry != null) {
                String filePath = destDirectory + File.separator + entry.getName();
                if (!entry.isDirectory()) {
                    extractFile(zipIn, filePath);
                } else {
                    File dir = new File(filePath);
                    dir.mkdir();
                }
                zipIn.closeEntry();
                entry = zipIn.getNextEntry();
            }
        }
    }

    private static void extractFile(ZipInputStream zipIn, String filePath) throws IOException {
        try (BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(filePath))) {
            byte[] bytesIn = new byte[4096];
            int read;
            while ((read = zipIn.read(bytesIn)) != -1) {
                bos.write(bytesIn, 0, read);
            }
        }
    }
}
