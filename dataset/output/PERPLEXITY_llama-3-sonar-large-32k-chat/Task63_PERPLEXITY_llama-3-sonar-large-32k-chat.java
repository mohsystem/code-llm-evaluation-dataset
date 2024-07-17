import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

import org.json.JSONObject;

public class RequestProcessor {
    public static String processRequest(String raw_data) throws IOException {
        // Ensure raw_data is encoded in UTF-8
        byte[] utf8Bytes = raw_data.getBytes(StandardCharsets.UTF_8);

        // Decode the raw_data using Base64
        byte[] decodedBytes = Base64.getDecoder().decode(utf8Bytes);
        String decodedData = new String(decodedBytes, StandardCharsets.UTF_8);

        // Deserialize the decoded data into its original format (e.g., JSON)
        JSONObject deserializedData = new JSONObject(decodedData);

        // Store the deserialized data in a variable
        String storedData = deserializedData.toString();

        // Return the stored data
        return storedData;
    }

    public static void main(String[] args) throws IOException {
        String raw_data = "Your raw data here";
        String result = processRequest(raw_data);
        System.out.println(result);
    }
}