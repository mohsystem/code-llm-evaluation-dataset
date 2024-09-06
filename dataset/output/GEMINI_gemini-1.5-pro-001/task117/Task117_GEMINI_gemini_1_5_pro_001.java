import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class Task117_GEMINI_gemini_1_5_pro_001 {

  public static void extractZip(String archivePath, String extractPath) throws IOException {
    try (ZipInputStream zis = new ZipInputStream(new FileInputStream(archivePath))) {
      ZipEntry zipEntry = zis.getNextEntry();
      while (zipEntry != null) {
        String fileName = zipEntry.getName();
        java.io.File newFile = new java.io.File(extractPath + java.io.File.separator + fileName);
        if (zipEntry.isDirectory()) {
          newFile.mkdirs();
        } else {
          new java.io.File(newFile.getParent()).mkdirs();
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
    String archivePath = args[0];
    String extractPath = args[1];

    if (archivePath.endsWith(".zip") || archivePath.endsWith(".ZIP")) {
      extractZip(archivePath, extractPath);
    } else {
      System.out.println("Unsupported archive format.");
    }
  }
}