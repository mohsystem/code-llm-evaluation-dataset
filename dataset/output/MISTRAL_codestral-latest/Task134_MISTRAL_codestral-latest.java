// Java
import java.util.HashMap;
import java.util.Map;

public class CryptoKeyManager {
    private Map<String, String> keys;

    public CryptoKeyManager() {
        keys = new HashMap<>();
    }

    public void addKey(String keyName, String keyValue) {
        keys.put(keyName, keyValue);
    }

    public String getKey(String keyName) {
        return keys.get(keyName);
    }

    public void removeKey(String keyName) {
        keys.remove(keyName);
    }
}