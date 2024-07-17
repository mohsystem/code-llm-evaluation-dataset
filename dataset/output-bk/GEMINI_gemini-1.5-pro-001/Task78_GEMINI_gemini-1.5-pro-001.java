import java.io.FileWriter;
import java.io.IOException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.PrivateKey;
import java.security.Security;

import org.bouncycastle.jce.provider.BouncyCastleProvider;
import org.bouncycastle.openssl.PEMWriter;

public class GenerateRSAKey {

    public static void main(String[] args) throws NoSuchAlgorithmException, NoSuchProviderException, IOException {
        // Add Bouncy Castle provider
        Security.addProvider(new BouncyCastleProvider());

        // Generate a new RSA key pair
        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA", "BC");
        keyGen.initialize(2048);
        KeyPair keyPair = keyGen.generateKeyPair();
        PrivateKey privateKey = keyPair.getPrivate();

        // Export the private key in OpenSSH format using PEMWriter
        try (PEMWriter pemWriter = new PEMWriter(new FileWriter("id_rsa"))) {
            pemWriter.writeObject(privateKey);
        }
    }
}