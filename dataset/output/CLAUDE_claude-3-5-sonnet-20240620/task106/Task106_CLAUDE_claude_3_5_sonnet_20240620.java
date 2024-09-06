
import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Scanner;

public class Task106_CLAUDE_claude_3_5_sonnet_20240620 {
    private BigInteger p, q, n, phi, e, d;
    private int bitLength = 1024;
    private SecureRandom r;

    public Task106_CLAUDE_claude_3_5_sonnet_20240620() {
        r = new SecureRandom();
        p = BigInteger.probablePrime(bitLength, r);
        q = BigInteger.probablePrime(bitLength, r);
        n = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(bitLength / 2, r);
        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0) {
            e = e.add(BigInteger.ONE);
        }
        d = e.modInverse(phi);
    }

    public BigInteger encrypt(BigInteger message) {
        return message.modPow(e, n);
    }

    public BigInteger decrypt(BigInteger encrypted) {
        return encrypted.modPow(d, n);
    }

    public static void main(String[] args) {
        Task106_CLAUDE_claude_3_5_sonnet_20240620 rsa = new Task106_CLAUDE_claude_3_5_sonnet_20240620();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a message to encrypt: ");
        String message = scanner.nextLine();

        BigInteger plaintext = new BigInteger(message.getBytes());
        BigInteger ciphertext = rsa.encrypt(plaintext);

        System.out.println("Encrypted message: " + ciphertext);

        BigInteger decrypted = rsa.decrypt(ciphertext);
        String decryptedMessage = new String(decrypted.toByteArray());

        System.out.println("Decrypted message: " + decryptedMessage);

        scanner.close();
    }
}
