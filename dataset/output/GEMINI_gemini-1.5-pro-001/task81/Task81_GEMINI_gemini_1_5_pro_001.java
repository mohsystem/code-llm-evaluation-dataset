import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class Task81_GEMINI_gemini_1_5_pro_001 {

    public static String calculateCertificateHash(String certificatePath, String hashAlgorithm) throws IOException, NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance(hashAlgorithm);
        FileInputStream fis = new FileInputStream(certificatePath);
        byte[] dataBytes = new byte[1024];
        int nread;
        while ((nread = fis.read(dataBytes)) != -1) {
            md.update(dataBytes, 0, nread);
        }
        byte[] mdbytes = md.digest();

        StringBuilder sb = new StringBuilder();
        for (byte mdbyte : mdbytes) {
            sb.append(Integer.toString((mdbyte & 0xff) + 0x100, 16).substring(1));
        }
        fis.close();
        return sb.toString();
    }

    public static boolean verifyCertificateHash(String certificatePath, String expectedHash, String hashAlgorithm) throws IOException, NoSuchAlgorithmException {
        String calculatedHash = calculateCertificateHash(certificatePath, hashAlgorithm);
        return calculatedHash.equalsIgnoreCase(expectedHash);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the path to the SSL certificate: ");
        String certFile = scanner.nextLine();
        System.out.print("Enter the expected hash value: ");
        String expectedHash = scanner.nextLine();
        System.out.print("Enter the hash algorithm used (e.g., SHA-256): ");
        String hashAlgo = scanner.nextLine();

        try {
            if (verifyCertificateHash(certFile, expectedHash, hashAlgo)) {
                System.out.println("Certificate hash matches!");
            } else {
                System.out.println("Certificate hash does not match.");
            }
        } catch (IOException | NoSuchAlgorithmException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}