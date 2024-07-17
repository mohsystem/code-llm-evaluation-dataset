
import java.security.*;
import java.util.Base64;

public class RSAKeyGenerator {
    public static void main(String[] args) throws Exception {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair keyPair = keyGen.generateKeyPair();
        
        PrivateKey privateKey = keyPair.getPrivate();
        byte[] privateKeyBytes = privateKey.getEncoded();
        
        String opensshKey = "-----BEGIN OPENSSH PRIVATE KEY-----\
";
        opensshKey += Base64.getEncoder().encodeToString(privateKeyBytes);
        opensshKey += "\
-----END OPENSSH PRIVATE KEY-----";
        
        System.out.println(opensshKey);
    }
}
