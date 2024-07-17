import org.json.JSONObject;

public class Main {
    public static void main(String[] args) {
        String jsonString = "{\"name\":\"John\", \"age\":30, \"car\":null}";
        JSONObject obj = new JSONObject(jsonString);
        System.out.println("Root Element: " + obj.keySet().toArray()[0]);
    }
}