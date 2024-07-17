
import java.util.*;

public class AccessControl {
    private static Map<String, List<String>> accessMatrix = new HashMap<>();
    
    static {
        accessMatrix.put("admin", Arrays.asList("server", "database", "network"));
        accessMatrix.put("developer", Arrays.asList("database", "codebase"));
        accessMatrix.put("tester", Arrays.asList("codebase", "testbed"));
        accessMatrix.put("user", Arrays.asList("application"));
    }
    
    public static boolean checkAccess(String userRole, String resource) {
        List<String> allowedResources = accessMatrix.get(userRole);
        return allowedResources != null && allowedResources.contains(resource);
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter your role: ");
        String userRole = scanner.nextLine().toLowerCase();
        
        System.out.print("Enter the resource you want to access: ");
        String resource = scanner.nextLine().toLowerCase();
        
        if (checkAccess(userRole, resource)) {
            System.out.println("Access granted to " + resource);
        } else {
            System.out.println("Access denied");
        }
        
        scanner.close();
    }
}
