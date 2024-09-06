import java.security.Key;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

public class Task134_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private Map<String, Key> keys;

    public Task134_PERPLEXITY_llama_3_sonar_large_32k_chat() {
        this.keys = new HashMap<>();
    }

    public void generateKey(String keyName) throws NoSuchAlgorithmException {
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        kpg.initialize(2048);
        KeyPair kp = kpg.generateKeyPair();
        Key key = kp.getPublic();
        this.keys.put(keyName, key);
    }

    public Key getKey(String keyName) {
        return this.keys.get(keyName);
    }

    public void deleteKey(String keyName) {
        this.keys.remove(keyName);
    }

    public String hashKey(String keyName) {
        Key key = this.getKey(keyName);
        if (key != null) {
            String keyString = key.toString();
            String sha256 = org.apache.commons.codec.digest.DigestUtils.sha256Hex(keyString);
            return sha256;
        } else {
            return null;
        }
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        Task134_PERPLEXITY_llama_3_sonar_large_32k_chat manager = new Task134_PERPLEXITY_llama_3_sonar_large_32k_chat();
        String keyName = "my_key";
        manager.generateKey(keyName);
        Key key = manager.getKey(keyName);
        System.out.println("Generated key for " + keyName + ": " + key);
        System.out.println("Hash of " + keyName + ": " + manager.hashKey(keyName));
        manager.deleteKey(keyName);
        System.out.println("Key " + keyName + " deleted: " + manager.getKey(keyName));
    }
}