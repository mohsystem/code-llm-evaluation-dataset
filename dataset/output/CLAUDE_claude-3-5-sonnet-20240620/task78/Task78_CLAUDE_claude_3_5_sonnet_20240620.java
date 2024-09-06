
import java.security.*;
import java.util.Base64;

public class Task78_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws Exception {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair pair = keyGen.generateKeyPair();
        PrivateKey privateKey = pair.getPrivate();

        // Convert to PKCS#8 format
        byte[] pkcs8EncodedKey = privateKey.getEncoded();

        // Base64 encode the key
        String encodedKey = Base64.getEncoder().encodeToString(pkcs8EncodedKey);

        // Format the key in OpenSSH format
        StringBuilder sshKey = new StringBuilder();
        sshKey.append("-----BEGIN OPENSSH PRIVATE KEY-----\\n");
        for (int i = 0; i < encodedKey.length(); i += 64) {
            sshKey.append(encodedKey, i, Math.min(i + 64, encodedKey.length())).append("\\n");
        }
        sshKey.append("-----END OPENSSH PRIVATE KEY-----\\n");

        System.out.println(sshKey.toString());
    }
}
