import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

public class Task121_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            JFrame frame = new JFrame("File Upload");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 200);
            frame.setLayout(new FlowLayout());

            JButton uploadButton = new JButton("Upload File");
            uploadButton.addActionListener(e -> {
                JFileChooser fileChooser = new JFileChooser();
                fileChooser.setDialogTitle("Choose a file to upload");
                FileNameExtensionFilter filter = new FileNameExtensionFilter("All Files", "*.*");
                fileChooser.setFileFilter(filter);

                int userSelection = fileChooser.showOpenDialog(frame);
                if (userSelection == JFileChooser.APPROVE_OPTION) {
                    File selectedFile = fileChooser.getSelectedFile();
                    try {
                        byte[] fileContent = Files.readAllBytes(selectedFile.toPath());
                        // Process the uploaded file here
                        // ...
                        JOptionPane.showMessageDialog(frame, "File uploaded successfully!");
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(frame, "Error uploading file: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                    }
                }
            });

            frame.add(uploadButton);
            frame.setVisible(true);
        });
    }
}