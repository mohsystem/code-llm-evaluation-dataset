import java.util.Base64;
import java.nio.charset.StandardCharsets;

class ProcessRequest {
    public static void main(String[] args) {
        // Example usage:
        String rawData = "eyJtZXNzYWdlIjogIkhlbGxvIHdvcmxkIn0=";
        Object processedData = processRequest(rawData);
        System.out.println(processedData);
    }

    public static Object processRequest(String rawData) {
        // Decode the raw_data using Base64
        byte[] decodedBytes = Base64.getDecoder().decode(rawData);

        // Convert the decoded bytes to a String
        String decodedString = new String(decodedBytes, StandardCharsets.UTF_8);

        // Deserialize the decoded string to JSON
        // ... Implementation for deserialization (replace with your logic)

        return decodedString;
    }
}