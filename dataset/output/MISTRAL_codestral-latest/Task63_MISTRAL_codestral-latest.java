// Java
import java.util.Base64;
import java.nio.charset.StandardCharsets;
import com.google.gson.Gson;

public class RequestProcessor {
    public static Object processRequest(String rawData) {
        byte[] decodedBytes = Base64.getDecoder().decode(rawData);
        String decodedString = new String(decodedBytes, StandardCharsets.UTF_8);
        Gson gson = new Gson();
        return gson.fromJson(decodedString, Object.class);
    }
}