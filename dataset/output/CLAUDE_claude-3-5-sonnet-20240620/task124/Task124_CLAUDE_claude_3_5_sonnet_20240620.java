
import java.util.Base64;
import java.util.HashMap;
import java.util.Map;

public class Task124_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String encrypt(String data) {
        return Base64.getEncoder().encodeToString(data.getBytes());
    }

    public static String decrypt(String encodedData) {
        byte[] decodedBytes = Base64.getDecoder().decode(encodedData);
        return new String(decodedBytes);
    }

    public static void main(String[] args) {
        Map<String, String> sensitiveData = new HashMap<>();
        sensitiveData.put("credit_card", "1234-5678-9012-3456");
        sensitiveData.put("ssn", "123-45-6789");
        sensitiveData.put("password", "mySecretPass123");

        Map<String, String> encryptedData = new HashMap<>();
        for (Map.Entry<String, String> entry : sensitiveData.entrySet()) {
            encryptedData.put(entry.getKey(), encrypt(entry.getValue()));
        }

        System.out.println("Encrypted data: " + encryptedData);

        Map<String, String> decryptedData = new HashMap<>();
        for (Map.Entry<String, String> entry : encryptedData.entrySet()) {
            decryptedData.put(entry.getKey(), decrypt(entry.getValue()));
        }

        System.out.println("Decrypted data: " + decryptedData);
    }
}
