import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.nio.charset.StandardCharsets;
import java.security.spec.PKCS8EncodedKeySpec;
import java.util.Base64;

public class Task78_OPENAI_gpt_4o {
  public static void main(String[] args) {
      try {
          KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
          keyGen.initialize(2048);
          KeyPair pair = keyGen.generateKeyPair();

          PublicKey publicKey = pair.getPublic();
          PrivateKey privateKey = pair.getPrivate();

          String privateKeyStr = Base64.getEncoder().encodeToString(privateKey.getEncoded());

          // PEM format
          String privateKeyPEM = "-----BEGIN PRIVATE KEY-----\n";
          privateKeyPEM += privateKeyStr.replaceAll("(.{64})", "$1\n");
          privateKeyPEM += "\n-----END PRIVATE KEY-----";

          System.out.println(privateKeyPEM);
      } catch (Exception e) {
          e.printStackTrace();
      }
  }
}