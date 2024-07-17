import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;

public class DeserializeData {
    public static Object deserializeData(byte[] data) {
        try {
            ByteArrayInputStream bis = new ByteArrayInputStream(data);
            ObjectInputStream ois = new ObjectInputStream(bis);
            return ois.readObject();
        } catch (Exception e) {
            System.out.println("Error deserializing data: " + e);
            return null;
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter serialized data: ");
        byte[] data = System.in.readAllBytes();
        Object deserializedData = deserializeData(data);
        System.out.println("Deserialized data: " + deserializedData);
    }
}