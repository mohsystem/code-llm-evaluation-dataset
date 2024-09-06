import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Task134_OPENAI_gpt_4o {
    public static void main(String[] args) throws Exception {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair pair = keyGen.generateKeyPair();
        PrivateKey privateKey = pair.getPrivate();
        saveKey(privateKey, "private_key.der");
        PrivateKey loadedKey = loadKey("private_key.der");
        System.out.println("Key: " + loadedKey);
    }

    public static void saveKey(PrivateKey key, String filename) throws Exception {
        Files.write(Paths.get(filename), key.getEncoded());
    }

    public static PrivateKey loadKey(String filename) throws Exception {
        byte[] keyBytes = Files.readAllBytes(Paths.get(filename));
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        return keyFactory.generatePrivate(new PKCS8EncodedKeySpec(keyBytes));
    }
}