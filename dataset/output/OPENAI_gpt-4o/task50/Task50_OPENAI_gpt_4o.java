// Java: Server to upload files using Spark Java
import static spark.Spark.*;
import java.io.File;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import spark.utils.IOUtils;

public class Task50_OPENAI_gpt_4o {
    private static final String UPLOAD_DIR = "uploads";

    public static void main(String[] args) {
        port(4567);
        File uploadDir = new File(UPLOAD_DIR);
        uploadDir.mkdir();
        staticFiles.externalLocation(UPLOAD_DIR);

        post("/upload", (req, res) -> {
            req.attribute("org.eclipse.jetty.multipartConfig", new MultipartConfigElement("/temp"));
            String contentType = req.raw().getContentType();
            if (contentType.startsWith("multipart/form-data")) {
                Part filePart = req.raw().getPart("file");
                if (filePart == null) {
                    return "{\"message\": \"No file part\"}";
                }
                String fileName = filePart.getSubmittedFileName();
                File file = new File(uploadDir, fileName);
                Files.copy(filePart.getInputStream(), file.toPath(), StandardCopyOption.REPLACE_EXISTING);
                return "{\"message\": \"File successfully uploaded\"}";
            }
            return "{\"message\": \"Invalid request content type\"}";
        });
    }
}