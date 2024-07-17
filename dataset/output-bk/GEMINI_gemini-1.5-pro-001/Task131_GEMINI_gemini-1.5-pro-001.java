import org.json.JSONObject;
import org.json.JSONArray;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the data to deserialize: ");
    String data = scanner.nextLine();
    scanner.close();
    
    try {
      Object deserializedData = deserialize(data);
      System.out.println("Deserialized data: " + deserializedData);
    } catch (Exception e) {
      System.out.println("Error: Invalid JSON data.");
    }
  }

  public static Object deserialize(String data) {
    if (data.startsWith("[")) {
      return new JSONArray(data);
    } else if (data.startsWith("{")) {
      return new JSONObject(data);
    } else {
      throw new IllegalArgumentException("Invalid JSON data.");
    }
  }
}