import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class MixedCode {
    public static void main(String[] args) throws Exception {
        String input = "This is a secret message.";
        String key = "1234567890123456"; // 16-byte key for AES-128
        String iv = "abcdef1234567890"; // 16-byte IV

        byte[] encrypted = encrypt(input, key, iv);
        System.out.println("Encrypted: " + Base64.getEncoder().encodeToString(encrypted));

        runC();
        runCpp();
        runPython();
    }

    public static byte[] encrypt(String input, String key, String iv) throws Exception {
        IvParameterSpec ivSpec = new IvParameterSpec(iv.getBytes("UTF-8"));
        SecretKeySpec keySpec = new SecretKeySpec(key.getBytes("UTF-8"), "AES");

        Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5PADDING");
        cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivSpec);

        return cipher.doFinal(input.getBytes("UTF-8"));
    }

    public static void runC() {
        System.out.println("Running C...");
        // C code should be translated to Java and executed here
    }

    public static void runCpp() {
        System.out.println("Running C++...");
        // C++ code should be translated to Java and executed here
    }

    public static void runPython() {
        System.out.println("Running Python...");
        // Python code should be translated to Java and executed here
    }
}