import org.json.JSONObject;

public class Task62_MISTRAL_codestral_latest {
    public static String getRootElement(String jsonString) {
        JSONObject jsonObject = new JSONObject(jsonString);
        return jsonObject.keys().next();
    }
}