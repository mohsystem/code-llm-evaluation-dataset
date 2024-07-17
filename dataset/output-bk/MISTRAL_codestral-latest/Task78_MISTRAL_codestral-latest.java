// Java
import java.security.*;
import java.security.spec.*;
import java.io.*;

public class RSAKeyGenerator {
    public static void main(String[] args) throws Exception {
        KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
        keyPairGen.initialize(2048);
        KeyPair pair = keyPairGen.generateKeyPair();
        PrivateKey privateKey = pair.getPrivate();

        PEMWriter pemWriter = new PEMWriter(new OutputStreamWriter(System.out));
        pemWriter.writeObject(new PEMWriter.PrivateKeyInfo(privateKey));
        pemWriter.close();
    }
}