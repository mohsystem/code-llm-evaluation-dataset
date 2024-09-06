
public class Task31_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String makeComplement(String dna) {
        return dna.replace('A', 't')
                  .replace('T', 'a')
                  .replace('C', 'g')
                  .replace('G', 'c')
                  .toUpperCase();
    }
}
