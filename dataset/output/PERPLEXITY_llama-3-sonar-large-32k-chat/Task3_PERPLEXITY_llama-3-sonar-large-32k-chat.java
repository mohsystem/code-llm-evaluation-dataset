import java.util.HashSet;
import java.util.Set;

public class Pangram {
    public boolean check(String sentence) {
        Set<Character> alphabet = new HashSet<>();
        for (char c : "abcdefghijklmnopqrstuvwxyz".toCharArray()) {
            alphabet.add(c);
        }
        for (char c : sentence.toLowerCase().replaceAll("[^a-z]", "").toCharArray()) {
            alphabet.remove(c);
        }
        return alphabet.isEmpty();
    }

    public static void main(String[] args) {
        Pangram pangram = new Pangram();
        System.out.println(pangram.check("The quick brown fox jumps over the lazy dog")); // true
        System.out.println(pangram.check("Hello World")); // false
    }
}