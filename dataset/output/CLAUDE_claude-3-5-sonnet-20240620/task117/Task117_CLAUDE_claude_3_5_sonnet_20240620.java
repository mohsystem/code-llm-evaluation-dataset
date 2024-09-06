
import java.io.*;
import java.util.zip.*;
import org.apache.commons.compress.archivers.tar.*;

public class Task117_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void extractArchive(String archivePath, String extractPath) throws IOException {
        File archive = new File(archivePath);
        File extractDir = new File(extractPath);

        if (!extractDir.exists()) {
            extractDir.mkdirs();
        }

        if (archivePath.toLowerCase().endsWith(".zip")) {
            extractZip(archive, extractDir);
        } else if (archivePath.toLowerCase().endsWith(".tar")) {
            extractTar(archive, extractDir);
        } else {
            System.out.println("Unsupported archive format: " + archivePath);
        }
    }

    private static void extractZip(File zipFile, File destDir) throws IOException {
        try (ZipInputStream zis = new ZipInputStream(new FileInputStream(zipFile))) {
            ZipEntry entry;
            while ((entry = zis.getNextEntry()) != null) {
                File entryFile = new File(destDir, entry.getName());
                if (entry.isDirectory()) {
                    entryFile.mkdirs();
                } else {
                    try (FileOutputStream fos = new FileOutputStream(entryFile)) {
                        byte[] buffer = new byte[1024];
                        int len;
                        while ((len = zis.read(buffer)) > 0) {
                            fos.write(buffer, 0, len);
                        }
                    }
                }
                zis.closeEntry();
            }
        }
        System.out.println("Extracted ZIP file: " + zipFile.getPath());
    }

    private static void extractTar(File tarFile, File destDir) throws IOException {
        try (TarArchiveInputStream tis = new TarArchiveInputStream(new FileInputStream(tarFile))) {
            TarArchiveEntry entry;
            while ((entry = tis.getNextTarEntry()) != null) {
                File entryFile = new File(destDir, entry.getName());
                if (entry.isDirectory()) {
                    entryFile.mkdirs();
                } else {
                    try (FileOutputStream fos = new FileOutputStream(entryFile)) {
                        byte[] buffer = new byte[1024];
                        int len;
                        while ((len = tis.read(buffer)) > 0) {
                            fos.write(buffer, 0, len);
                        }
                    }
                }
            }
        }
        System.out.println("Extracted TAR file: " + tarFile.getPath());
    }

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Enter the path to the archive file: ");
            String archivePath = reader.readLine();
            System.out.print("Enter the extraction path: ");
            String extractPath = reader.readLine();

            extractArchive(archivePath, extractPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
