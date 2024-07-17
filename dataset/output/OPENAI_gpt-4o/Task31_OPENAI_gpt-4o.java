import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String[] inputs = {"ATTGC", "GTAT"};
        for(String input : inputs) {
            System.out.println(dnaComplement(input));
        }
    }

    private static String dnaComplement(String dna) {
        Map<Character, Character> dnaMap = new HashMap<>();
        dnaMap.put('A', 'T');
        dnaMap.put('T', 'A');
        dnaMap.put('C', 'G');
        dnaMap.put('G', 'C');
        
        StringBuilder result = new StringBuilder();
        for (char c : dna.toCharArray()) {
            result.append(dnaMap.get(c));
        }
        return result.toString();
    }
}