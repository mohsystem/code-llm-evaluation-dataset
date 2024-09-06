import java.util.Scanner;
import org.json.JSONObject;

public class Task131_GEMINI_gemini_1_5_pro_001 {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter the data to deserialize: ");
    String data = scanner.nextLine();
    scanner.close();

    try {
      JSONObject deserializedData = new JSONObject(data);
      System.out.println(deserializedData.toString(2)); // Pretty print with indentation
    } catch (Exception e) {
      System.out.println("Error deserializing data: " + e.getMessage());
    }
  }
}