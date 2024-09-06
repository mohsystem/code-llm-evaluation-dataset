import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;

public class Task131_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static Object deserializeData(byte[] data) {
        try (ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(data))) {
            return ois.readObject();
        } catch (Exception e) {
            System.err.println("Error deserializing data: " + e.getMessage());
            return null;
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter serialized data (in hexadecimal format): ");
        String hexData = System.console().readLine();
        byte[] data = hexStringToByteArray(hexData);
        Object deserializedData = deserializeData(data);
        System.out.println("Deserialized data: " + deserializedData);
    }

    public static byte[] hexStringToByteArray(String s) {
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
                    + Character.digit(s.charAt(i + 1), 16));
        }
        return data;
    }
}