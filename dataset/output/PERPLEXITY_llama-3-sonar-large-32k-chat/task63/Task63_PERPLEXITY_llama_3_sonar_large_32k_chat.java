import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import org.json.JSONObject;

public class Task63_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static Object processRequest(String request) throws IOException {
        byte[] raw_data = request.getBytes(StandardCharsets.UTF_8);
        byte[] decoded_data = Base64.getDecoder().decode(raw_data);
        String deserialized_data = new String(decoded_data, StandardCharsets.UTF_8);
        return new JSONObject(deserialized_data);
    }
}