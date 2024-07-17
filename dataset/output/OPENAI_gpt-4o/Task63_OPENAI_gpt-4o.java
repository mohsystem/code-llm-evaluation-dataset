import java.util.Base64;
import org.json.JSONObject;

public class RequestProcessor {
    public static void main(String[] args) {
        String requestData = "eyJrZXkiOiAiVmFsdWUifQ=="; // Base64 encoded JSON {"key": "Value"}

        // Step 1: Retrieve and decode raw data
        byte[] decodedBytes = Base64.getDecoder().decode(requestData);
        String decodedData = new String(decodedBytes);

        // Step 2: Deserialize JSON data
        JSONObject jsonObject = new JSONObject(decodedData);

        // Step 3: Store deserialized data in variable and return it
        String storedData = jsonObject.toString();
        System.out.println(storedData);
    }
}