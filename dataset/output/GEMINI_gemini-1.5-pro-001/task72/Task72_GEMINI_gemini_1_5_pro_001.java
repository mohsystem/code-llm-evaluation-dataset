import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Arrays;
import javax.xml.bind.DatatypeConverter;

public class Task72_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) throws Exception {
        // Static Initialization Vector (IV) - Must be 16 bytes
        byte[] iv = "ThisIsMyStaticIV".getBytes();
        IvParameterSpec ivspec = new IvParameterSpec(iv);

        // Encryption Key - Must be 16, 24, or 32 bytes
        byte[] key = "ThisIsMySecretKey".getBytes();
        SecretKeySpec keySpec = new SecretKeySpec(key, "AES");

        // Data to be encrypted
        String data = "This is some secret data.";
        System.out.println("Original Data: " + data);

        // Encrypt the data
        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivspec);
        byte[] encryptedData = cipher.doFinal(data.getBytes());

        // Print encrypted data in hexadecimal format
        System.out.println("Encrypted Data (Hex): " + DatatypeConverter.printHexBinary(encryptedData));
    }
}