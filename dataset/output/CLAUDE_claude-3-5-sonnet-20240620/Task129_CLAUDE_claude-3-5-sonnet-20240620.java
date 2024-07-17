
import java.io.*;
import java.net.*;

public class FileRetriever {
    public static void retrieveFile(String filename) {
        String serverUrl = "http://example.com/files/";  // Replace with actual server URL
        String fileUrl = serverUrl + filename;
        
        try {
            URL url = new URL(fileUrl);
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");
            
            int responseCode = connection.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                InputStream inputStream = connection.getInputStream();
                FileOutputStream outputStream = new FileOutputStream(filename);
                
                byte[] buffer = new byte[4096];
                int bytesRead;
                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                }
                
                outputStream.close();
                inputStream.close();
                System.out.println("File \'" + filename + "\' successfully retrieved and saved.");
            } else {
                System.out.println("Failed to retrieve file. Response Code: " + responseCode);
            }
            connection.disconnect();
        } catch (IOException e) {
            System.out.println("Error retrieving file: " + e.getMessage());
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the filename to retrieve: ");
        String userFilename = reader.readLine();
        retrieveFile(userFilename);
    }
}
