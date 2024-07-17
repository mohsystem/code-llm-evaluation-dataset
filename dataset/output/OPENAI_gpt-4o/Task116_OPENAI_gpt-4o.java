import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static {
        System.loadLibrary("userops"); // Assuming we have a native library for C and C++ code
    }

    private native void dropPrivileges();

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the username: ");
        String username = reader.readLine();

        System.out.print("Enter the new password: ");
        String password = reader.readLine();

        ProcessBuilder pb = new ProcessBuilder("sudo", "passwd", username);
        pb.redirectErrorStream(true);
        
        Process process = pb.start();
        try (OutputStream out = process.getOutputStream()) {
            out.write((password + "
").getBytes());
            out.write((password + "
").getBytes());
            out.flush();
        }
        
        BufferedReader processOutput = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        while ((line = processOutput.readLine()) != null) {
            System.out.println(line);
        }
        
        main.dropPrivileges();
    }
}