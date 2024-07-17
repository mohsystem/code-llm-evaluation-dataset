import java.io.FileInputStream;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class CheckCertificateHash {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the path to the SSL certificate file: ");
        String certificateFile = scanner.nextLine();
        System.out.print("Enter the expected SHA-256 hash: ");
        String expectedHash = scanner.nextLine();

        if (checkCertificateHash(certificateFile, expectedHash)) {
            System.out.println("Certificate hash matches!");
        } else {
            System.out.println("Certificate hash does not match.");
        }
    }

    public static boolean checkCertificateHash(String certificatePath, String expectedHash) {
        try (FileInputStream fis = new FileInputStream(certificatePath)) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] data = new byte[1024];
            int bytesRead;
            while ((bytesRead = fis.read(data)) != -1) {
                md.update(data, 0, bytesRead);
            }
            byte[] calculatedHashBytes = md.digest();
            String calculatedHash = bytesToHex(calculatedHashBytes);
            return calculatedHash.equalsIgnoreCase(expectedHash);
        } catch (NoSuchAlgorithmException | IOException e) {
            System.err.println("Error checking certificate hash: " + e.getMessage());
            return false;
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }
}