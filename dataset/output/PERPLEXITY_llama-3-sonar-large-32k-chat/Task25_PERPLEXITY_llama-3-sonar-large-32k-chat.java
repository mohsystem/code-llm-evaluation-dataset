public class Main {
    public static void main(String[] args) {
        String[] lines = {"a", "b", "c"};
        for (String line : numberLines(lines)) {
            System.out.println(line);
        }
    }

    public static String[] numberLines(String[] lines) {
        for (int i = 0; i < lines.length; i++) {
            lines[i] = (i + 1) + ": " + lines[i];
        }
        return lines;
    }
}