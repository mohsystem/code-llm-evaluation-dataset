
import java.io.*;
import java.util.Base64;

public class Deserializer {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Enter the serialized data: ");
            String serializedData = reader.readLine();
            byte[] decodedBytes = Base64.getDecoder().decode(serializedData);
            ByteArrayInputStream bis = new ByteArrayInputStream(decodedBytes);
            ObjectInputStream ois = new ObjectInputStream(bis);
            Object deserializedObject = ois.readObject();
            System.out.println("Deserialized data: " + deserializedObject);
            ois.close();
        } catch (Exception e) {
            System.out.println("Error: Invalid input or deserialization failed.");
        }
    }
}
