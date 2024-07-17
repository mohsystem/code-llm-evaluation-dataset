import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PrivilegeDropper {
    public static void main(String[] args) {
        try {
            // Perform privileged operation
            Process process = Runtime.getRuntime().exec("sudo passwd " + args[0]);
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            process.waitFor();

            // Drop privileges
            System.setProperty("java.security.manager", "no");
            System.setSecurityManager(null);

            // Verify privileges dropped
            process = Runtime.getRuntime().exec("whoami");
            reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            process.waitFor();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}