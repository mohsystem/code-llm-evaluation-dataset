import java.security.cert.Certificate;
import java.security.cert.CertificateEncodingException;
import java.security.cert.CertificateFactory;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SSLCertificateVerifier {
    public static void main(String[] args) throws CertificateEncodingException, NoSuchAlgorithmException {
        String knownHash = "your_known_hash_here";
        String certificatePath = "path_to_your_certificate.cer";

        CertificateFactory cf = CertificateFactory.getInstance("X.509");
        Certificate cert = cf.generateCertificate(SSLCertificateVerifier.class.getResourceAsStream(certificatePath));

        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] certBytes = cert.getEncoded();
        byte[] hashBytes = md.digest(certBytes);

        StringBuilder sb = new StringBuilder();
        for (byte b : hashBytes) {
            sb.append(String.format("%02x", b));
        }
        String calculatedHash = sb.toString();

        if (calculatedHash.equals(knownHash)) {
            System.out.println("Certificate matches the known hash.");
        } else {
            System.out.println("Certificate does not match the known hash.");
        }
    }
}