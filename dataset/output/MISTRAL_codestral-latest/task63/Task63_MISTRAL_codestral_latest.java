import java.util.Base64;
import java.nio.charset.StandardCharsets;
import com.google.gson.Gson;

public class Task63_MISTRAL_codestral_latest {
    public static Object processRequest(String rawData) {
        byte[] decodedBytes = Base64.getDecoder().decode(rawData);
        String decodedData = new String(decodedBytes, StandardCharsets.UTF_8);
        Gson gson = new Gson();
        return gson.fromJson(decodedData, Object.class);
    }
}