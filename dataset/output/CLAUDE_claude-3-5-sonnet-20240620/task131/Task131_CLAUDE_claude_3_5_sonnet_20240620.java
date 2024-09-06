
import java.util.Scanner;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.JsonProcessingException;

public class Task131_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter serialized data (JSON format): ");
        String serializedData = scanner.nextLine();
        
        ObjectMapper objectMapper = new ObjectMapper();
        try {
            Object deserializedData = objectMapper.readValue(serializedData, Object.class);
            System.out.println("Deserialized data:");
            System.out.println(objectMapper.writerWithDefaultPrettyPrinter().writeValueAsString(deserializedData));
        } catch (JsonProcessingException e) {
            System.out.println("Error: Invalid JSON data");
        }
        
        scanner.close();
    }
}
