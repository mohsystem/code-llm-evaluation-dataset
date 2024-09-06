import java.io.*;
import java.util.zip.*;
import org.apache.commons.compress.archivers.tar.*;

public class Task117_OPENAI_gpt_4o {
    public static void extractZip(String filePath, String extractTo) throws IOException {
        byte[] buffer = new byte[1024];
        File folder = new File(extractTo);
        if (!folder.exists()) {
            folder.mkdir();
        }
        ZipInputStream zis = new ZipInputStream(new FileInputStream(filePath));
        ZipEntry ze = zis.getNextEntry();
        while (ze != null) {
            String fileName = ze.getName();
            File newFile = new File(extractTo + File.separator + fileName);
            new File(newFile.getParent()).mkdirs();
            FileOutputStream fos = new FileOutputStream(newFile);
            int len;
            while ((len = zis.read(buffer)) > 0) {
                fos.write(buffer, 0, len);
            }
            fos.close();
            ze = zis.getNextEntry();
        }
        zis.closeEntry();
        zis.close();
    }

    public static void extractTar(String filePath, String extractTo) throws IOException {
        TarArchiveInputStream tis = new TarArchiveInputStream(new FileInputStream(filePath));
        TarArchiveEntry entry;
        while ((entry = (TarArchiveEntry) tis.getNextEntry()) != null) {
            File outputFile = new File(extractTo, entry.getName());
            if (entry.isDirectory()) {
                outputFile.mkdirs();
            } else {
                outputFile.getParentFile().mkdirs();
                OutputStream os = new FileOutputStream(outputFile);
                byte[] buffer = new byte[1024];
                int len;
                while ((len = tis.read(buffer)) != -1) {
                    os.write(buffer, 0, len);
                }
                os.close();
            }
        }
        tis.close();
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java Task117_OPENAI_gpt_4o <archive_path> <extract_to>");
            System.exit(1);
        }

        String archivePath = args[0];
        String extractTo = args[1];

        try {
            if (archivePath.endsWith(".zip")) {
                extractZip(archivePath, extractTo);
            } else if (archivePath.endsWith(".tar")) {
                extractTar(archivePath, extractTo);
            } else {
                System.out.println("Unsupported file type");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}