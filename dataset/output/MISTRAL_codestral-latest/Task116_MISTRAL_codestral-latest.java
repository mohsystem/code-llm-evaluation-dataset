// Java
import java.io.IOException;

public class DropPrivileges {
    public static void main(String[] args) {
        try {
            Process p = Runtime.getRuntime().exec("id");
            p.waitFor();

            // Perform privileged operations here

            // Drop privileges
            String[] cmd = {"su", "-", "username", "-c", "id"};
            p = Runtime.getRuntime().exec(cmd);
            p.waitFor();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}