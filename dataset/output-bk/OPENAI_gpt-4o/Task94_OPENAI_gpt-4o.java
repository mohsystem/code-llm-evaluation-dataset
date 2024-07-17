import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class MultiLangSort {
    public static void main(String[] args) throws Exception {
        List<String> lines = new ArrayList<>();
        String fileName = "records.txt";
        
        BufferedReader reader = new BufferedReader(new FileReader(fileName));
        String line;
        while ((line = reader.readLine()) != null) {
            lines.add(line);
        }
        reader.close();
        
        lines = lines.stream()
                     .sorted(Comparator.comparing(s -> s.split("=")[0]))
                     .collect(Collectors.toList());
        
        for (String l : lines) {
            System.out.println(l);
        }
        
        runC();
        runCPP();
        runPython();
    }

    public static void runC() {
        ProcessBuilder builder = new ProcessBuilder("sh", "-c", "./c_program");
        try {
            Process process = builder.start();
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static void runCPP() {
        ProcessBuilder builder = new ProcessBuilder("sh", "-c", "./cpp_program");
        try {
            Process process = builder.start();
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static void runPython() {
        ProcessBuilder builder = new ProcessBuilder("python3", "python_program.py");
        try {
            Process process = builder.start();
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}