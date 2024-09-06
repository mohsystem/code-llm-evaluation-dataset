import java.io.FileWriter;
import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.Security;
import java.security.interfaces.RSAPrivateKey;
import org.bouncycastle.jce.provider.BouncyCastleProvider;
import org.bouncycastle.openssl.jcajce.JcaPEMWriter;
import org.bouncycastle.util.io.pem.PemObject;

public class Task78_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws NoSuchAlgorithmException, NoSuchProviderException, IOException {
        // Add Bouncy Castle provider
        Security.addProvider(new BouncyCastleProvider());

        // Generate RSA key pair
        KeyPairGenerator generator = KeyPairGenerator.getInstance("RSA", "BC");
        generator.initialize(2048);
        KeyPair keyPair = generator.generateKeyPair();
        RSAPrivateKey privateKey = (RSAPrivateKey) keyPair.getPrivate();

        // Write private key to PEM file
        PemObject pemObject = new PemObject("OPENSSH PRIVATE KEY", privateKey.getEncoded());
        JcaPEMWriter pemWriter = new JcaPEMWriter(new FileWriter("id_rsa"));
        pemWriter.writeObject(pemObject);
        pemWriter.close();

        System.out.println("Private key saved to id_rsa");
    }
}