import org.json.JSONObject;

public class Task62_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        String jsonString = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
        JSONObject jsonObject = new JSONObject(jsonString);
        System.out.println(jsonObject.getClass().getSimpleName());
    }
}