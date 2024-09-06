import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;

public class Task81_OPENAI_gpt_4o {

    public static String getCertHash(String certPath) throws Exception {
        byte[] certData = Files.readAllBytes(Paths.get(certPath));
        CertificateFactory certFactory = CertificateFactory.getInstance("X.509");
        X509Certificate cert = (X509Certificate) certFactory.generateCertificate(Files.newInputStream(Paths.get(certPath)));
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] certHash = md.digest(cert.getEncoded());
        StringBuilder sb = new StringBuilder();
        for (byte b : certHash) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        try {
            String knownHash = "your_known_hash_here";
            String certPath = "path_to_your_certificate.crt";
            String certHash = getCertHash(certPath);
            
            if (certHash.equals(knownHash)) {
                System.out.println("Certificate matches the known hash.");
            } else {
                System.out.println("Certificate does not match the known hash.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}