import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.util.Base64;
import java.io.PrintWriter;

public class RSAKeyGenerator {
    public static void generateKey() throws Exception {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair pair = keyGen.generateKeyPair();
        PrivateKey privateKey = pair.getPrivate();
        String base64PrivateKey = Base64.getEncoder().encodeToString(privateKey.getEncoded());
        try (PrintWriter out = new PrintWriter("id_rsa_java.pem")) {
            out.println("-----BEGIN RSA PRIVATE KEY-----");
            out.println(base64PrivateKey);
            out.println("-----END RSA PRIVATE KEY-----");
        }
    }

    public static void main(String[] args) {
        try {
            generateKey();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}