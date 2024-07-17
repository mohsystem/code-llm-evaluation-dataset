import java.io.*;
import java.nio.file.*;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

public class EncryptDecrypt {
    private static final String key = "1234567890123456";
    private static final String algorithm = "AES";

    public static void encrypt(String input, String output) throws Exception {
        SecretKeySpec keySpec = new SecretKeySpec(key.getBytes(), algorithm);
        Cipher cipher = Cipher.getInstance(algorithm);
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);

        byte[] inputBytes = Files.readAllBytes(Paths.get(input));
        byte[] outputBytes = cipher.doFinal(inputBytes);
        Files.write(Paths.get(output), outputBytes);
    }

    public static void decrypt(String input, String output) throws Exception {
        SecretKeySpec keySpec = new SecretKeySpec(key.getBytes(), algorithm);
        Cipher cipher = Cipher.getInstance(algorithm);
        cipher.init(Cipher.DECRYPT_MODE, keySpec);

        byte[] inputBytes = Files.readAllBytes(Paths.get(input));
        byte[] outputBytes = cipher.doFinal(inputBytes);
        Files.write(Paths.get(output), outputBytes);
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 4) {
            System.out.println("Usage: java EncryptDecrypt <encrypt/decrypt> <inputFile> <outputFile>");
            return;
        }

        if (args[0].equalsIgnoreCase("encrypt")) {
            encrypt(args[1], args[2]);
        } else if (args[0].equalsIgnoreCase("decrypt")) {
            decrypt(args[1], args[2]);
        } else {
            System.out.println("Invalid command.");
        }
    }
}