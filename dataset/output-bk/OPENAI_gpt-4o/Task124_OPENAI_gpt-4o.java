import java.util.Base64;

public class SecureData {
    private String encodedData;
    
    public SecureData(String data) {
        this.encodedData = encodeData(data);
    }

    private String encodeData(String data) {
        return Base64.getEncoder().encodeToString(data.getBytes());
    }

    private String decodeData() {
        return new String(Base64.getDecoder().decode(this.encodedData));
    }

    public static void main(String[] args) {
        SecureData sd = new SecureData("4111-1111-1111-1111");
        System.out.println("Encoded Data (Java): " + sd.encodedData);
        System.out.println("Decoded Data (Java): " + sd.decodeData());
    }
}