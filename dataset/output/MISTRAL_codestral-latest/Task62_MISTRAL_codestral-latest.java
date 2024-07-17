import org.json.JSONObject;

public class Main {
    public static void main(String[] args) {
        String jsonString = "{\"key1\":\"value1\",\"key2\":\"value2\"}";
        JSONObject jsonObject = new JSONObject(jsonString);
        System.out.println("Root element: " + jsonObject.keys().next());
    }
}