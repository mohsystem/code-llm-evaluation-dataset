
import java.io.FileInputStream;
import java.security.MessageDigest;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.Base64;

public class SSLCertificateHashChecker {
    public static void main(String[] args) {
        String certPath = "path/to/certificate.crt";
        String knownHash = "known_hash_value";

        try {
            FileInputStream fis = new FileInputStream(certPath);
            CertificateFactory cf = CertificateFactory.getInstance("X.509");
            X509Certificate cert = (X509Certificate) cf.generateCertificate(fis);

            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] derCert = cert.getEncoded();
            md.update(derCert);
            byte[] digest = md.digest();

            String calculatedHash = Base64.getEncoder().encodeToString(digest);

            if (calculatedHash.equals(knownHash)) {
                System.out.println("Certificate hash matches the known hash.");
            } else {
                System.out.println("Certificate hash does not match the known hash.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
