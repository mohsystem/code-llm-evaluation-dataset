import java.security.MessageDigest;
import javax.xml.bind.DatatypeConverter;

public class SSLCheck {
    public static void main(String[] args) {
        String cert = "sample_certificate";  // Replace with actual SSL certificate content
        String knownHash = "known_hash";  // Replace with actual known hash
        
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] digest = md.digest(cert.getBytes());
            String hash = DatatypeConverter.printHexBinary(digest).toLowerCase();
            
            if (hash.equals(knownHash.toLowerCase())) {
                System.out.println("Java: Certificate matches the known hash.");
            } else {
                System.out.println("Java: Certificate does not match the known hash.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}