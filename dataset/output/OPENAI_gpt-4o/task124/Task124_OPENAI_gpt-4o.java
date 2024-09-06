// Java code
import java.util.HashMap;

class SensitiveData {
    private HashMap<String, String> data = new HashMap<>();

    public void storeData(String key, String value) {
        data.put(key, value);
    }

    public String retrieveData(String key) {
        return data.getOrDefault(key, "Data not found");
    }

    public static void main(String[] args) {
        SensitiveData sensitiveData = new SensitiveData();
        sensitiveData.storeData("credit_card", "1234-5678-9012-3456");
        System.out.println(sensitiveData.retrieveData("credit_card"));
    }
}