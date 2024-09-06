import org.json.JSONObject;
import org.json.JSONArray;
import org.json.JSONException;

public class Task62_GEMINI_gemini_1_5_pro_001 {

    public static Object getRootElement(String jsonString) {
        try {
            if (jsonString.startsWith("[")) {
                return new JSONArray(jsonString);
            } else if (jsonString.startsWith("{")) {
                return new JSONObject(jsonString);
            } else {
                // Handle primitive values
                if ("true".equalsIgnoreCase(jsonString) || "false".equalsIgnoreCase(jsonString)) {
                    return Boolean.parseBoolean(jsonString);
                } else if (jsonString.matches("-?\\d+(\\.\\d+)?")) {
                    try {
                        return Integer.parseInt(jsonString);
                    } catch (NumberFormatException e) {
                        return Double.parseDouble(jsonString);
                    }
                } else {
                    return jsonString;
                }
            }
        } catch (JSONException e) {
            System.err.println("Invalid JSON string: " + e.getMessage());
            return null;
        }
    }

    public static void main(String[] args) {
        String jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
        Object rootElement = getRootElement(jsonString);
        System.out.println(rootElement);
    }
}