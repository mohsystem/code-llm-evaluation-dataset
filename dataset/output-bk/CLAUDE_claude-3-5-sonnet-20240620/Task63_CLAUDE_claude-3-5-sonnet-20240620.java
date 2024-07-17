
import java.util.Base64;
import java.nio.charset.StandardCharsets;
import org.json.JSONObject;

public class RequestProcessor {
    public static JSONObject processRequest(String raw_data) {
        try {
            // Ensure raw_data is UTF-8 encoded
            byte[] utf8Bytes = raw_data.getBytes(StandardCharsets.UTF_8);
            String utf8EncodedData = new String(utf8Bytes, StandardCharsets.UTF_8);

            // Decode Base64
            byte[] decodedBytes = Base64.getDecoder().decode(utf8EncodedData);
            String decodedData = new String(decodedBytes, StandardCharsets.UTF_8);

            // Deserialize JSON
            JSONObject deserializedData = new JSONObject(decodedData);

            // Store and return the deserialized data
            return deserializedData;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        String raw_data = "eyJuYW1lIjogIkpvaG4gRG9lIiwgImFnZSI6IDMwfQ==";
        JSONObject result = processRequest(raw_data);
        System.out.println(result);
    }
}
