import java.security.cert.Certificate;
import java.security.cert.CertificateEncodingException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.MessageDigest;
import java.net.Socket;
import javax.net.ssl.SSLSocketFactory;

public class Task81_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        String hostname = "example.com";
        int port = 443;
        String expectedHash = "expected_hash_here";

        SSLSocketFactory factory = (SSLSocketFactory) SSLSocketFactory.getDefault();
        Socket socket = factory.createSocket(hostname, port);
        Certificate[] certs = (Certificate[]) socket.getSession().getPeerCertificates();
        X509Certificate cert = (X509Certificate) certs[0];
        byte[] derCert = cert.getEncoded();
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashBytes = md.digest(derCert);
        StringBuilder hexString = new StringBuilder();
        for (byte b : hashBytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        String certHash = hexString.toString();
        if (certHash.equals(expectedHash)) {
            System.out.println("Certificate matches the expected hash");
        } else {
            System.out.println("Certificate does not match the expected hash");
        }
    }
}