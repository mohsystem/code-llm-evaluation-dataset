import org.json.JSONObject;
import org.json.JSONArray;

class Solution {
    public static Object parseJSON(String jsonString) {
        jsonString = jsonString.trim();
        if (jsonString.startsWith("{")) {
            return new JSONObject(jsonString);
        } else if (jsonString.startsWith("[")) {
            return new JSONArray(jsonString);
        } else {
            // Handle cases like strings, numbers, booleans etc.
            return jsonString;
        }
    }

    public static void main(String[] args) {
        String jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
        Object jsonObject = parseJSON(jsonString);
        System.out.println(jsonObject.toString());
    }
}