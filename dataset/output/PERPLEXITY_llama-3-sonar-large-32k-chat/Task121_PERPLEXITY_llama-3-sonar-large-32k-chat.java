import java.io.*;

public class FileUploader {
    public static void uploadFile(String filePath) throws IOException {
        File file = new File(filePath);
        FileInputStream fis = new FileInputStream(file);
        FileOutputStream fos = new FileOutputStream("uploaded_" + file.getName());
        byte[] buffer = new byte[1024];
        int len;
        while ((len = fis.read(buffer)) > 0) {
            fos.write(buffer, 0, len);
        }
        fis.close();
        fos.close();
    }

    public static void main(String[] args) throws IOException {
        System.out.print("Enter the file path: ");
        String filePath = System.console().readLine();
        uploadFile(filePath);
        System.out.println("File uploaded successfully!");
    }
}