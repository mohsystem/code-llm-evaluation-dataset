import java.io.*;
import java.net.*;

public class FileRetriever {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the filename to retrieve: ");
        try {
            String filename = reader.readLine();
            String urlStr = "http://example.com/" + filename;

            URL url = new URL(urlStr);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");

            if (connection.getResponseCode() == HttpURLConnection.HTTP_OK) {
                InputStream inputStream = connection.getInputStream();
                FileOutputStream outputStream = new FileOutputStream(filename);

                byte[] buffer = new byte[4096];
                int bytesRead;
                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                }

                outputStream.close();
                inputStream.close();

                System.out.println("File '" + filename + "' has been retrieved successfully.");
            } else {
                System.out.println("Failed to retrieve the file '" + filename + "'.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}