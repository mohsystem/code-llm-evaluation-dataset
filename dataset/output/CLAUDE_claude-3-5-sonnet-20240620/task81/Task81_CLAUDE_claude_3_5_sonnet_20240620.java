
import javax.net.ssl.*;
import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.cert.Certificate;
import java.security.cert.CertificateEncodingException;

public class Task81_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String getCertificateHash(String hostname, int port) throws Exception {
        SSLSocketFactory factory = HttpsURLConnection.getDefaultSSLSocketFactory();
        SSLSocket socket = (SSLSocket) factory.createSocket(hostname, port);
        
        try {
            socket.startHandshake();
            Certificate[] certs = socket.getSession().getPeerCertificates();
            Certificate cert = certs[0];
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] encodedCert = cert.getEncoded();
            byte[] hashedCert = digest.digest(encodedCert);
            return bytesToHex(hashedCert);
        } finally {
            socket.close();
        }
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

    public static void checkCertificateHash(String hostname, String knownHash) {
        try {
            String certHash = getCertificateHash(hostname, 443);
            if (certHash.equals(knownHash)) {
                System.out.println("Certificate hash for " + hostname + " matches the known hash.");
            } else {
                System.out.println("Certificate hash for " + hostname + " does not match the known hash.");
                System.out.println("Calculated hash: " + certHash);
                System.out.println("Known hash:     " + knownHash);
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        String hostname = "www.example.com";
        String knownHash = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"; // Example hash
        checkCertificateHash(hostname, knownHash);
    }
}
