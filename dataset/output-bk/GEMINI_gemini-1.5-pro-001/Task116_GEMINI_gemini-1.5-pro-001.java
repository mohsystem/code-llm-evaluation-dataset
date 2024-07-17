import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ChangePassword {

    public static void main(String[] args) throws IOException, InterruptedException {
        if (System.getProperty("user.name").equals("root")) {
            System.err.println("This program should not be run as root. Exiting.");
            System.exit(1);
        }

        ProcessBuilder pb = new ProcessBuilder("sudo", "/bin/bash", "-c",
                "echo Enter the username: && read username;" +
                        "echo Enter the new password: && read -s password;" +
                        "echo $password | sudo chpasswd <<< \"$username:$password\"; " +
                        "echo Password for user '$username' changed successfully.;"
        );

        Process process = pb.start();

        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(line);
        }

        int exitCode = process.waitFor();
        if (exitCode != 0) {
            System.err.println("An error occurred while changing the password.");
            System.exit(1);
        }
    }
}