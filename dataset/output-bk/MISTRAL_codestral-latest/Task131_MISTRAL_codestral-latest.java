import com.google.gson.Gson;
import java.lang.*;

public class Main {
    public static Object deserializeJson(String jsonData) {
        Gson gson = new Gson();
        return gson.fromJson(jsonData, Object.class);
    }
}