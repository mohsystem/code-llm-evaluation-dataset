import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        String[] names = {"Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman"};
        Arrays.sort(names, Comparator.comparingInt(s -> s.split(" ")[1].length()).thenComparing(s -> s.split(" ")[1]));
        System.out.println(Arrays.toString(names));
    }
}