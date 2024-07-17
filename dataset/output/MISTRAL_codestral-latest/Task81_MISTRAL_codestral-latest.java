import java.security.MessageDigest;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {
    public static void main(String[] args) throws Exception {
        String certPath = "path_to_certificate.crt";
        String knownHash = "known_hash";

        boolean matches = certHashMatches(certPath, knownHash);
        System.out.println("Certificate hash matches known hash: " + matches);
    }

    private static boolean certHashMatches(String certPath, String knownHash) throws Exception {
        CertificateFactory cf = CertificateFactory.getInstance("X.509");
        FileInputStream fis = new FileInputStream(certPath);
        X509Certificate cert = (X509Certificate) cf.generateCertificate(fis);
        fis.close();

        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] der = cert.getEncoded();
        md.update(der);
        byte[] digest = md.digest();

        String calculatedHash = bytesToHex(digest);
        return calculatedHash.equals(knownHash);
    }

    private static String bytesToHex(byte[] hash) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : hash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
}