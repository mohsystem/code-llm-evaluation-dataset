import java.io.*;
import java.nio.file.*;
import java.util.regex.*;
import java.util.*;

public class Task100_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if(args.length != 2) {
            System.out.println("Usage: java Task100_OPENAI_gpt_4o <pattern> <filename>");
            System.exit(1);
        }

        String patternString = args[0];
        String filename = args[1];

        try {
            String content = new String(Files.readAllBytes(Paths.get(filename)));
            Pattern pattern = Pattern.compile(patternString);
            Matcher matcher = pattern.matcher(content);

            List<String> matches = new ArrayList<>();
            while(matcher.find()) {
                matches.add(matcher.group());
            }

            matches.forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}