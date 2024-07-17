import java.io.FileOutputStream;
import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

public class KeyManager {

    public static void generateKeys() throws NoSuchAlgorithmException, IOException {
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
        keyGen.initialize(2048);
        KeyPair pair = keyGen.generateKeyPair();
        PrivateKey priKey = pair.getPrivate();
        PublicKey pubKey = pair.getPublic();

        try (FileOutputStream fos = new FileOutputStream("rsa_private.key")) {
            fos.write(priKey.getEncoded());
        }

        try (FileOutputStream fos = new FileOutputStream("rsa_public.key")) {
            fos.write(pubKey.getEncoded());
        }
    }

    public static void main(String[] args) throws NoSuchAlgorithmException, IOException {
        generateKeys();
        System.out.println("Keys are generated and stored as rsa_private.key and rsa_public.key");
    }
}