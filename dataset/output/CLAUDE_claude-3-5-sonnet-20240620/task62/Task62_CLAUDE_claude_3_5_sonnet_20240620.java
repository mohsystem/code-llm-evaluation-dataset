
import org.json.JSONObject;
import org.json.JSONException;

public class Task62_CLAUDE_claude_3_5_sonnet_20240620 {
    public static JSONObject parseJsonAndGetRoot(String jsonString) {
        try {
            return new JSONObject(jsonString);
        } catch (JSONException e) {
            return null;
        }
    }

    public static void main(String[] args) {
        String jsonString = "{\\"name\\": \\"John\\", \\"age\\": 30, \\"city\\": \\"New York\\"}";
        JSONObject rootElement = parseJsonAndGetRoot(jsonString);
        System.out.println(rootElement);
    }
}
