import java.net.*;
import java.io.*;

public class FileRetriever {
    public static void retrieveFile(String filename) throws IOException {
        Socket sock = new Socket("localhost", 8080);
        OutputStream os = sock.getOutputStream();
        os.write(filename.getBytes());
        InputStream is = sock.getInputStream();
        byte[] data = new byte[1024];
        int bytesRead = is.read(data);
        if (bytesRead > 0) {
            FileOutputStream fos = new FileOutputStream(filename);
            fos.write(data, 0, bytesRead);
            fos.close();
            System.out.println("File retrieved successfully");
        } else {
            System.out.println("File not found on the server");
        }
        sock.close();
    }

    public static void main(String[] args) throws IOException {
        System.out.print("Enter the filename: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String filename = br.readLine();
        retrieveFile(filename);
    }
}