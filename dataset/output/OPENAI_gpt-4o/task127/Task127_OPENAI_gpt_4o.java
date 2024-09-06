import java.io.*;

public class Task127_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String sourcePath = "/path/to/source/file.txt";
        String destPath = "/path/to/dest/tmp_file.txt";

        try {
            File source = new File(sourcePath);
            File dest = new File(destPath);
            
            if (!source.exists()) {
                throw new FileNotFoundException("Source file does not exist");
            }
            
            copyFile(source, dest);
            System.out.println("File copied successfully.");
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("Error: An I/O error occurred.");
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }

    private static void copyFile(File source, File dest) throws IOException {
        try (InputStream is = new FileInputStream(source); OutputStream os = new FileOutputStream(dest)) {
            byte[] buffer = new byte[1024];
            int length;
            while ((length = is.read(buffer)) > 0) {
                os.write(buffer, 0, length);
            }
        }
    }
}