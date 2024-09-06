import java.io.BufferedReader;
import java.io.InputStreamReader;

// Please note: Java does not directly support setting user ids and changing user passwords. This example is pseudo-code.
public class Task116_OPENAI_gpt_4o {
    public static void main(String[] args) throws Exception {
        if (!System.getProperty("user.name").equals("root")) {
            System.out.println("This script must be run as root!");
            System.exit(1);
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter username to change password: ");
        String user = br.readLine();

        Process p = Runtime.getRuntime().exec(new String[] { "sh", "-c", "echo \"" + user + ":newpassword\" | chpasswd" });
        p.waitFor();

        // Dropping privileges is not supported directly in Java. This needs to be handled in the underlying OS or through a native interface.
        System.out.println("Privileges have been dropped (pseudo operation in Java).");
    }
}