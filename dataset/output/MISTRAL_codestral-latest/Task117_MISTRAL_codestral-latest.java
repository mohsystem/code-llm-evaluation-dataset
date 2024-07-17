// Java
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class ExtractZip {
    private static final int BUFFER_SIZE = 4096;

    public static void main(String[] args) {
        String zipFilePath = "path_to_your_zip_file.zip";
        String destDir = "destination_directory";
        extractZip(zipFilePath, destDir);
    }

    private static void extractZip(String zipFilePath, String destDir) {
        File dir = new File(destDir);
        if (!dir.exists()) dir.mkdirs();
        byte[] buffer = new byte[BUFFER_SIZE];
        try (ZipInputStream zis = new ZipInputStream(new FileInputStream(zipFilePath))) {
            ZipEntry ze = zis.getNextEntry();
            while (ze != null) {
                String fileName = ze.getName();
                File newFile = newFile(destDir + File.separator + fileName);
                if (ze.isDirectory()) {
                    newFile.mkdirs();
                } else {
                    extractFile(zis, newFile, buffer);
                }
                ze = zis.getNextEntry();
            }
            zis.closeEntry();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    private static void extractFile(ZipInputStream zis, File newFile, byte[] buffer) throws IOException {
        new File(newFile.getParent()).mkdirs();
        try (FileOutputStream fos = new FileOutputStream(newFile)) {
            int len;
            while ((len = zis.read(buffer)) > 0) {
                fos.write(buffer, 0, len);
            }
        }
    }
}