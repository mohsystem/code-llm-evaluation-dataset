import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.attribute.PosixFilePermission;
import java.util.HashSet;
import java.util.Set;

public class Task101_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws IOException {
        String scriptContent = "#!/bin/bash\necho \"Hello from script.sh!\"\n";
        Files.write(Paths.get("script.sh"), scriptContent.getBytes());

        Set<PosixFilePermission> perms = new HashSet<>();
        perms.add(PosixFilePermission.OWNER_READ);
        perms.add(PosixFilePermission.OWNER_WRITE);
        perms.add(PosixFilePermission.OWNER_EXECUTE);
        perms.add(PosixFilePermission.GROUP_READ);
        perms.add(PosixFilePermission.OTHERS_READ);
        perms.add(PosixFilePermission.GROUP_EXECUTE);
        Files.setPosixFilePermissions(Paths.get("script.sh"), perms);
    }
}