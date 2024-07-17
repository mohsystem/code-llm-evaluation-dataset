
import org.json.JSONObject;
import org.json.JSONException;

public class JSONParser {
    public static Object parseJSON(String jsonString) {
        try {
            JSONObject jsonObject = new JSONObject(jsonString);
            return jsonObject;
        } catch (JSONException e) {
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        String jsonString = "{\\"name\\":\\"John\\",\\"age\\":30,\\"city\\":\\"New York\\"}";
        Object rootElement = parseJSON(jsonString);
        System.out.println("Root element: " + rootElement);
    }
}
