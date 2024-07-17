import org.json.JSONObject;

public class Main {
    public static void main(String[] args) {
        String jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
        JSONObject jsonObject = new JSONObject(jsonString);
        System.out.println("Root element: " + jsonObject.keys().next());
    }
}