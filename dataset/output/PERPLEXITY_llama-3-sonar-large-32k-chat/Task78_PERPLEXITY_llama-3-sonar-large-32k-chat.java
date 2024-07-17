import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.spec.RSAKeyGenParameterSpec;
import java.util.Base64;

public class Main {
    public static void main(String[] args) throws Exception {
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        kpg.initialize(new RSAKeyGenParameterSpec(2048, RSAKeyGenParameterSpec.F4));
        KeyPair kp = kpg.generateKeyPair();
        PrivateKey privateKey = kp.getPrivate();

        String privateKeyOpenSSH = "-----BEGIN OPENSSH PRIVATE KEY-----
" +
                Base64.getEncoder().encodeToString(privateKey.getEncoded()) +
                "
-----END OPENSSH PRIVATE KEY-----";

        System.out.println(privateKeyOpenSSH);
    }
}