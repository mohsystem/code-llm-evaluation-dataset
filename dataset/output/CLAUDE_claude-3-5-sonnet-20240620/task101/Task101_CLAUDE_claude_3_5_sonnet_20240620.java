
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.attribute.PosixFilePermission;
import java.util.HashSet;
import java.util.Set;

public class Task101_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        String filename = "script.sh";
        String content = "#!/bin/bash\\necho \\"Hello, World!\\"";

        try {
            // Create the file
            FileWriter writer = new FileWriter(filename);
            writer.write(content);
            writer.close();

            // Make it executable
            Set<PosixFilePermission> perms = new HashSet<>();
            perms.add(PosixFilePermission.OWNER_READ);
            perms.add(PosixFilePermission.OWNER_WRITE);
            perms.add(PosixFilePermission.OWNER_EXECUTE);
            perms.add(PosixFilePermission.GROUP_READ);
            perms.add(PosixFilePermission.GROUP_EXECUTE);
            perms.add(PosixFilePermission.OTHERS_READ);
            perms.add(PosixFilePermission.OTHERS_EXECUTE);

            Files.setPosixFilePermissions(Paths.get(filename), perms);

            System.out.println("File created and made executable successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
