import java.util.Random;
import java.math.BigInteger;

public class Task106_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private static final Random random = new Random();

    private static BigInteger gcd(BigInteger a, BigInteger b) {
        if (b.compareTo(BigInteger.ZERO) == 0) {
            return a;
        } else {
            return gcd(b, a.mod(b));
        }
    }

    private static BigInteger multiplicativeInverse(BigInteger e, BigInteger phi) {
        BigInteger x = BigInteger.ZERO;
        BigInteger y = BigInteger.ONE;
        BigInteger a = phi;
        BigInteger b = e;

        while (b.compareTo(BigInteger.ZERO) != 0) {
            BigInteger q = a.divide(b);
            BigInteger temp = b;
            b = a.mod(b);
            a = temp;
            temp = x;
            x = y.subtract(q.multiply(x));
            y = temp;
        }

        if (y.compareTo(BigInteger.ZERO) < 0) {
            y = y.add(phi);
        }

        return y;
    }

    private static KeyPair generateKeyPair(int p, int q) {
        BigInteger n = BigInteger.valueOf(p).multiply(BigInteger.valueOf(q));
        BigInteger phi = BigInteger.valueOf(p - 1).multiply(BigInteger.valueOf(q - 1));

        BigInteger e = new BigInteger(phi.bitLength(), random);
        while (gcd(e, phi).compareTo(BigInteger.ONE) != 0) {
            e = new BigInteger(phi.bitLength(), random);
        }

        BigInteger d = multiplicativeInverse(e, phi);
        return new KeyPair(new PublicKey(e, n), new PrivateKey(d, n));
    }

    private static class KeyPair {
        private PublicKey publicKey;
        private PrivateKey privateKey;

        public KeyPair(PublicKey publicKey, PrivateKey privateKey) {
            this.publicKey = publicKey;
            this.privateKey = privateKey;
        }
    }

    private static class PublicKey {
        private BigInteger e;
        private BigInteger n;

        public PublicKey(BigInteger e, BigInteger n) {
            this.e = e;
            this.n = n;
        }
    }

    private static class PrivateKey {
        private BigInteger d;
        private BigInteger n;

        public PrivateKey(BigInteger d, BigInteger n) {
            this.d = d;
            this.n = n;
        }
    }

    private static byte[] encrypt(PublicKey publicKey, byte[] plaintext) {
        byte[] cipher = new byte[plaintext.length];
        for (int i = 0; i < plaintext.length; i++) {
            cipher[i] = (byte) (Math.pow(plaintext[i], publicKey.e.intValue()) % publicKey.n.intValue());
        }
        return cipher;
    }

    private static byte[] decrypt(PrivateKey privateKey, byte[] ciphertext) {
        byte[] plain = new byte[ciphertext.length];
        for (int i = 0; i < ciphertext.length; i++) {
            plain[i] = (byte) (Math.pow(ciphertext[i], privateKey.d.intValue()) % privateKey.n.intValue());
        }
        return plain;
    }

    public static void main(String[] args) {
        int p = 61;
        int q = 53;
        KeyPair keyPair = generateKeyPair(p, q);
        System.out.println("Public Key: " + keyPair.publicKey.e + ", " + keyPair.publicKey.n);
        System.out.println("Private Key: " + keyPair.privateKey.d + ", " + keyPair.privateKey.n);

        String message = "Hello, World!";
        byte[] encryptedMessage = encrypt(keyPair.publicKey, message.getBytes());
        System.out.println("Encrypted Message: " + new String(encryptedMessage));

        byte[] decryptedMessage = decrypt(keyPair.privateKey, encryptedMessage);
        System.out.println("Decrypted Message: " + new String(decryptedMessage));
    }
}