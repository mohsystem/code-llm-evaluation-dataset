// Java
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.util.Base64;

public class Task78_MISTRAL_codestral_latest {
    public static void main(String[] args) throws NoSuchAlgorithmException {
        // Generate RSA key pair
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(2048);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();

        // Get private key
        PrivateKey privateKey = keyPair.getPrivate();

        // Encode private key in OpenSSH format
        PKCS8EncodedKeySpec pkcs8EncodedKeySpec = new PKCS8EncodedKeySpec(privateKey.getEncoded());
        String privateKeyBase64 = Base64.getEncoder().encodeToString(pkcs8EncodedKeySpec.getEncoded());

        // Print the private key in OpenSSH format
        System.out.println("-----BEGIN OPENSSH PRIVATE KEY-----\n" + privateKeyBase64 + "\n-----END OPENSSH PRIVATE KEY-----");
    }
}